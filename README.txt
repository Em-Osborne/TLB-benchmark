To run this file type ./main followed by a space and then a number. 

The TLB is the "translatioin lookaside buffer." This is part of a chips 
memory management unit (MMU) and is a hardware cache of popular virtual
-to-physical address translations (basically an address translation cache). 
If the CPU doesn't find the translation in the TLB (a TLB miss), then the 
hardware has to access the page table and update the TLB. This takes 
a little longer than if the address is in the TLB. 

This program makes an array whose size is based on the number the user inputs. 
Then it iterates through and accesses the things in that array. The program times
the loop that iterates through the array and then divides that by the size of the
array so that we get an average lookup time. This average lookup time is small
when the array is small because everything can fit in the TLB. When the array 
is asking for more memory and not all of the translations can fit in the TLB it 
starts to get slower. 

To accurately test this I didn't want to cores of my laptop to be dividing up
the lookup tasks so I pinned the process to one core. I think the accuracy of this 
test would be improved by accessing the things in the array at random rather than
in order because there might be some prefetching/predicting involved in what the 
computer chooses to keep in the TLB. 