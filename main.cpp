//tlb benchmark 

#include <iostream> 
#include <chrono>
#include <cassert>
#include <unistd.h> 

using namespace std;
using namespace std::chrono;


short CorePin(int coreID)
{
  short status=0;
  int nThreads = 1;
  //std::cout<<nThreads;
  cpu_set_t set;
  std::cout<<"\nPinning to Core:"<<coreID<<"\n";
  CPU_ZERO(&set);

  if(coreID == -1)
  {
    status=-1;
    std::cout<<"CoreID is -1"<<"\n";
    return status;
  }

  if(coreID > nThreads)
  {
    std::cout<<"Invalid CORE ID"<<"\n";
    return status;
  }

  CPU_SET(coreID,&set);
  if(sched_setaffinity(0, sizeof(cpu_set_t), &set) < 0)
  {
    std::cout<<"Unable to Set Affinity"<<"\n";
    return -1;
  }
  return 1;
}


int work(auto input){
	
	int num_pages = stoi(input);
	int page_size = getpagesize();
	page_size = page_size/4;
	int* array = new int[num_pages*page_size];
	int v = 0; 
	const auto start1 = steady_clock::now();
	
	for(int i = 0; i < num_pages; i += 1){ 
		for(int j = 0; j < num_pages*page_size; j+= page_size){
			v = array[j];
		}
	}
	
	const auto end1 = steady_clock::now();

	
		  
	cout << "Average time per access: "<<((duration_cast<duration<double>>(end1 - start1).count())/num_pages) << " seconds " <<
          std::endl;

	return v;
}

int main(int argc, char *argv[]){
	CorePin(0);
	work(argv[1]);
	return (0);
}