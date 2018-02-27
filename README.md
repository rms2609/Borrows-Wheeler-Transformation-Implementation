# Borrows-Wheeler-Transformation-Implementation
BWT is used in data compression techniques such as bzip2. It is a block sorting compression technique which prepares the data to be used as an input for data compression algorithms like Huffman Tree or Arithmetic Encoding.
It was proposed by Michael Burrows and David Wheeler in 1994. 
Reference Here: http://www.hpl.hp.com/techreports/Compaq-DEC/SRC-RR-124.pdf

In order to get the most optimised results very first a Run Length Encoding and Move to Front Encoding should be carried out which helps in efficient soring of various strings involved in BorrowS Wheeler Transformation.
Thus the order followed should be:
input data -> RLE -> MTF -> BWT.
