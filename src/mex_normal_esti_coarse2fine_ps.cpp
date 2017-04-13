//
//  normal_esti_coarse2fine_ps.cpp
//  pm_stereo
//
//  Created by KaiWu on Sep/9/16.
//  Copyright © 2016 KaiWu. All rights reserved.
//

#include "normal_esti_coarse2fine_ps.hpp"
#include "mex.h"

using Eigen::Matrix;
using Eigen::Matrix2i;
using Eigen::Matrix2d;
using Eigen::MatrixXi;
using Eigen::Vector2i;
using Eigen::Vector2d;
using Eigen::VectorXi;
using Eigen::VectorXd;
using Eigen::Map;

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
    double *pov_tar = mxGetPr(prhs[0]);
    int r = mxGetM(prhs[0]);
    int c = mxGetN(prhs[0]);
    // mexPrintf("r: %d, c: %d\n", r, c);
    MatrixXd ov_tar = Map<MatrixXd>(pov_tar, r, c);
    
    vector<MatrixXd> ov_ref(2);
    double *pov_ref_spec = mxGetPr(prhs[1]);
    r = mxGetM(prhs[1]);
    c = mxGetN(prhs[1]);
    ov_ref[0] = Map<MatrixXd>(pov_ref_spec, r, c); // ov_ref_spec
    
    double *pov_ref_diff = mxGetPr(prhs[2]);
    r = mxGetM(prhs[2]);
    c = mxGetN(prhs[2]);
    ov_ref[1] = Map<MatrixXd>(pov_ref_diff, r, c); // ov_ref_diff
    
    int *pov_tar_ind = (int *)mxGetData(prhs[3]);
    r = mxGetM(prhs[3]);
    c = mxGetN(prhs[3]);
    VectorXi ov_tar_ind = Map<VectorXi>(pov_tar_ind, r, c);
    for (int i = 0; i < 100; ++i)
    	mexPrintf("%d\n", pov_tar_ind[i]);
    // for (int i = 0; i < 100; ++i)
    // 	mexPrintf("ind: %d\n", ov_tar_ind(i));
    
    vector<VectorXi> ov_ref_ind(2);
    int *pov_ref_spec_ind = (int *)mxGetData(prhs[4]);
    r = mxGetM(prhs[4]);
    c = mxGetN(prhs[4]);
    ov_ref_ind[0] = Map<VectorXi>(pov_ref_spec_ind, r, c); // ov_ref_spec_ind

    int *pov_ref_diff_ind = (int *)mxGetData(prhs[5]);
    r = mxGetM(prhs[5]);
    c = mxGetN(prhs[5]);
    ov_ref_ind[1] = Map<VectorXi>(pov_ref_diff_ind, r, c); // ov_ref_diff_ind
    
    int *psize_tar = (int *)mxGetData(prhs[6]);
    r = mxGetM(prhs[6]);
    c = mxGetN(prhs[6]);
    Vector2i size_tar = Map<Vector2i>(psize_tar);
    // mexPrintf("size_tar: %d, %d\n", size_tar(0), size_tar(1));
    
    vector<Vector2i> size_ref(2);
    int *psize_ref = (int *)mxGetData(prhs[7]);
    r = mxGetM(prhs[7]);
    c = mxGetN(prhs[7]);
    Matrix2i size_ref_mat = Map<Matrix2i>(psize_ref, r, c);
    size_ref[0] = size_ref_mat.col(0);
    size_ref[1] = size_ref_mat.col(1);
    // mexPrintf("size_ref 1: %d, %d\n", size_ref[0](0), size_ref[0](1));
    // mexPrintf("size_ref 2: %d, %d\n", size_ref[1](0), size_ref[1](1));
    
    vector<Vector2d, Eigen::aligned_allocator<Vector2d> > center(2);
    double *pcenter = mxGetPr(prhs[8]);
    r = mxGetM(prhs[8]);
    c = mxGetN(prhs[8]);
    Matrix2d center_mat = Map<Matrix2d>(pcenter, r, c);
    center[0] = center_mat.col(0);
    center[1] = center_mat.col(1);
    // mexPrintf("center 1: %.1f, %.1f\n", center[0](0), center[0](1));
    // mexPrintf("center 2: %.1f, %.1f\n", center[1](0), center[1](1));

    vector<double> radius(2);
    double *pradius = mxGetPr(prhs[9]);
    r = mxGetM(prhs[9]);
    c = mxGetN(prhs[9]);
    Vector2d radius_mat = Map<Vector2d>(pradius, r, c);
    radius[0] = radius_mat(0);
    radius[1] = radius_mat(1);
    // mexPrintf("radius 1: %.1f\n", radius[0]);
    // mexPrintf("radius 2: %.1f\n", radius[1]);

    plhs[0] = mxCreateDoubleMatrix(3, mxGetN(prhs[0]), mxREAL);
    double* norm_map = mxGetPr(plhs[0]);
	// norm_map = esti_norm(ov_tar, ov_ref, ov_tar_ind, ov_ref_ind, size_tar, size_ref, center, radius);
	
	// delete [] norm_map;
}