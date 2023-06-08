/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:12:58 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 15:17:13 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

ssize_t	find_new_line(char	*source)
{
	ssize_t	index;

	index = 0;
	while (source[index] != '\0' && source[index] != '\n')					//Scans parameter source for NULL or \n
		index++;
	if (source[index] == '\n')												//If it found a \n return size=index
		return (index);
	return (-1);															//If source[index] is NULL, return -1.
}

char	*trim_line_buffer(char	*line_buffer)
{
	ssize_t	end_of_line;													//Signed size_t so we can store error value of -1
	size_t	total_buffer_len;
	char	*temp_buffer;

	end_of_line = find_new_line(line_buffer);								//Finds the amount of characters before \n char in line_buffer.
	total_buffer_len = ft_strlen(line_buffer);								//Finds the amount of chars in the buffer in total.
	if (end_of_line == -1)													//If line_buffer ends with '\0', return 0, we can return the string -> it is already terminated properly.
		return (0);
	end_of_line++;															//Increment by 1 so we can read what comes after the \n
	temp_buffer = ft_substr(line_buffer, end_of_line, total_buffer_len);	//Use substr to load the remainder of the buffer into temp.
	if (*temp_buffer == '\0')
	{
		free(temp_buffer);
		temp_buffer = NULL;
	}
	line_buffer[end_of_line] = '\0';										//Null terminate, cause why not. Probably avoids a segfault in some edge case. 
	return (temp_buffer);													//temp_buffer will be the string after \n.
}

char	*get_full_chunk(int fd, char *previous_read, char *chunk_buffer)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	bytes_read = 1;															//Bytes_read set to 1 to run loop at least once
	while (bytes_read != 0)
	{
		bytes_read = read(fd, chunk_buffer, BUFFER_SIZE);					//Using read to load BUFFER_SIZE bytes of data from fd into chunk_buffer, read returns nbr of bytes read.
		if (bytes_read == -1)												//If read fails, it returns -1, so return NULL
			return (NULL);
		else if (bytes_read == 0)											//If 0 bytes are read it means were at E0F or file is empty so break loop.
			break ;
		chunk_buffer[bytes_read] = '\0';									//Null terminate buffer so that we can read it (so for strjoin later).
		if (!previous_read)
			previous_read = ft_empty_string();								//If Previous_read is uninitialized (aka, it is first call of gnl) we allocate an empty string to it.
		temp_buffer = previous_read;
		previous_read = ft_strjoin(temp_buffer, chunk_buffer);				//Concatenate temp and chunk into previous_read. It should really be called "maybe_previous_read" but just imagine thats what it says here.
		free(temp_buffer);
		temp_buffer = NULL;
		if (ft_strchr(chunk_buffer, '\n'))									//If theres a \n in the string were good and can break loop.
			break ;
	}
	return (previous_read);
}

char	*get_next_line(int fd)												//Main function that takes the file descriptor fd.
{
	static char	*previous_read;												//Static buffer that remembers the previous variable (aka, chars after \n) 
	char		*chunk_buffer;
	char		*line_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)											//Error handling, invalid fd or BUFFER_SIZE
		return (NULL);
	chunk_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);					//Mallocing buffer for size BUFFER_SIZE
	if (!chunk_buffer)
		return (NULL);
	line_buffer = get_full_chunk(fd, previous_read, chunk_buffer);			//Loading a buffer of size N guaranteed to contain a \n and/or NULL char
	free(chunk_buffer);
	chunk_buffer = NULL;
	if (!line_buffer)														//If line_buffer allocation fails, free static char and return NULL
	{
		free(previous_read);
		previous_read = NULL;
		return (NULL);
	}
	previous_read = trim_line_buffer(line_buffer);							//Terminate line_buffer (at i=\n) and load remainder into previous_read for next call.
	return (line_buffer);
}
