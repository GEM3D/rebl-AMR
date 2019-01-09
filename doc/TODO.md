
1) 16 Jan 2017: 
	
	Cmake CMakeList.txt is currently developed for the linux systems
        need to make some adjustments to make it suitable for Mac and Windows

2) 17 Jan 2017:

	Add vesrion control such that if the version of the external package is less than the one recommended, generate a warning
 
3) 18 Jan 2017:
	FindZoltan.cmake has a hard time finding the zoltan package, I hard coded the ZOLTAN_DIR for now. all other packages are found easily
	I notices that the difference between the zoltan and MPI and Parmetis and .. is the lack of env. variable $PATH
	need to fix this before the final release

4) 24 May 2017 
        Removal of the trees from the forest should be defined for forest classs such that the allocated memory is freed as well

5) 24 May 2017 
	Some of the iterators  in the forest, may be replaced with std::advance(), instead of using find and the next  

6) 18 May 2018 

	Would recomend changing the list data structure to hash-table, it is not crucial though as each processor has only 
	a handfull of seeds	

7) 21 May 2018 

	Remove  unnecessary procesor topology tree nodes for each processor
        by deleting elements that are not in the destination list
