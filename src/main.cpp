#include "ReblAmr.h"

/** \mainpage
 *
 *
 *  <STRONG>
 *   "rebl-AMR: An Open-Source Software for Binarized-Octree Mesh Generation around Immersed Geometries"
 * </STRONG>
 *
 * \details
 * This software generates forest of octrees for an immersed geometry. <br>
 * reble-AMR uses red-black tree data strcture to store the nodes in a Z-curve compliant fashion. <br>
 * This project is part of the <STRONG>NSF-GEM3D </STRONG>Award No. 1440638. <br>
 *
 *	Required Libraries:
 *
 *      (1)  CMAKE
 *      (2)  MPI (MPI 3.0 standard compliant version)
 *      (3)  Zoltan
 *      (4)  ParMetis
 *      (5)  HDF5
 *
 *      Usage:
 *      mpirun -np <number of processes> progName input/myGeometry.stl <params.txt
 *
 * @authors     Jaber J. Hasbestan and Inanc Senocak (PI) <br>
 *
 * @date        Feb 2018
 *
 * @copyright  (c)
 * Department of Mechanical Engineering and Materials Science <br>
 * University of Pittsburgh, Pittsburgh, PA <br>
 * <br>
 *
 * Please refere to either of the JCP papers \cite Hasbestan2018 and \cite Hasbestan2017 listed below if you are using this code
 *
 * @ref  "[1] Jaber J. Hasbestan and Inanc Senocak. Binarized-octree generation for cartesian adaptive mesh refinement around immersed geometries. Journal of Computational Physics, 368:179–195, sep 2018"
 *
 * @ref  "[2] Jaber J. Hasbestan and Inanc Senocak. A short note on the use of the red textendash black tree in cartesian adaptive mesh refinement algorithms. Journal of Computational Physics, 351:473–477, dec 2017" 
 *  
 *
 *  \image html f16_bunny.png
 *  
 *   
 *  <STRONG>
 *	Subject to GPL 3.0 license
 *  </STRONG>
 *
*/

int main( int argcs, char *pArgs[] )
{
 
   int proclevel = atoi (pArgs[2]);
   int meshlevel = atoi (pArgs[3]);

    unsigned int i, j, k, l;
    int my_rank, comsize;

    real ancestorlength[3] = {2.0f, 2.0f, 2.0f};
    real ancestorcoords[3] = {0.0f, 0.0f, 0.0f};
 
    ReblAmr<TREESIZE, real, PROCSIZE, uint> AMR( argcs, pArgs, ancestorlength, ancestorcoords, npx, npy, npz );

    AMR.distributeTopology( );
    AMR.forestConstruct(argcs,pArgs,ancestorlength, ancestorcoords, npx,npy, npz );
    AMR.createComPattern( );   

    real xx[3] = {0.0, 0.0, 0.0};

    AMR.moveGeometry(xx);
    AMR.refineForest();
    AMR.getTotalMeshSize();
    AMR.writeMesh();
    AMR.writeRunInfo();

}

