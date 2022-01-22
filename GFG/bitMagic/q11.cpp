// C++ program to swap even and
// odd bits of a given number
#include <bits/stdc++.h>
using namespace std;

// Function to swap even
// and odd bits
unsigned int swapBits(unsigned int x)
{
	// Get all even bits of x
	unsigned int even_bits = x & 0xAAAAAAAA;
  	cout<<even_bits<<endl;

	// Get all odd bits of x
	unsigned int odd_bits = x & 0x55555555;
    cout<<odd_bits<<endl;
  
	even_bits >>= 1; // Right shift even bits
	odd_bits <<= 1; // Left shift odd bits
	cout<<even_bits<<endl;
  	cout<<odd_bits<<endl;
  
	return (even_bits | odd_bits); // Combine even and odd bits
}

// Driver code
int main()
{
	unsigned int x = 55; // 00110111 00100010 00010101
	//00100010
  	//00010101
  
  
	// Output is 43 (00101011)
	cout<<swapBits(x);

	return 0;
}

