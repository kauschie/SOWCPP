// checkpoints 12.10 - 12.15

// 12.10
// seekg sets the seek get or read position
//
// seekp sets the seek put or write position
//
// 12.11
//
// tellg returns the read position
//
// tellp returns the write position
//
// 12.12
//
// these file access flags are used when using seekp/seekg and they indicate how the offsets should be
// calculated
//
// ios::beg / calculates the read/write position based on starting from the beginning of the file
// ios::end / calculates the read/write position based on starting from the end of the file
// ios::cur / calculates the read/write position based on the current read/write position
//
// 12.13
//
// 0
//
// 12.14
//
// sets write position the 101st byte (byte 100) from the beginning
// sets write position to the 11th byte (byte 10) from the last
// sets read position 26 bytes (byte 25) back from the current position
// sets read position 31 bytes (byte 20) from the current position
//
// 12.15
//
// opens info.dat for input and output
// opens info.dat for input and output in append mode (output will be appended to the end of the file)
// opens info.dat for input and outpit, if file exists it goes to the end of it
// opens info.dat for input and output in binary mode
