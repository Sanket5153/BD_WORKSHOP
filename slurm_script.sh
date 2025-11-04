#!/bin/bash
#SBATCH -N 1
#SBATCH --ntasks-per-node=12
#SBATCH --cpus-per-task=1
#SBATCH --time=03:00:00
#SBATCH --job-name=Gromacs
#SBATCH --error=%J.err
#SBATCH --output=%J.out
#SBATCH --partition=cpu
ulimit -s unlimited

cd $SLURM_SUBMIT_DIR

source /home/apps/spack/share/spack/setup-env.sh
spack load gromacs/cdd72j5

export OMP_NUM_THREADS=1

# Total number of MPI tasks
TOTAL_TASKS=$((SLURM_NNODES * SLURM_NTASKS_PER_NODE))

(time mpirun -np $TOTAL_TASKS gmx_mpi mdrun -ntomp 1  -s /home/gamadhuri/Sanket/Gromacs/water-cut1.0_GMX50_bare/3072/water.tpr) >& $SLURM_NNODES-N-$SLURM_JOBID-out
