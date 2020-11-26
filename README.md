# Next Line

Prototype:

int	get_next_line(int fd, char **line);

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Describe:

- This function read the file with defined buffer size (default 4096).
Reading file is minimized. And function save buffer until the file end.
Supports multiple files.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Return values:

- If reading file was success, the function will return (int)1.
If file is over, the function will return (int)0.
And if error, the function will return (int)-1.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
