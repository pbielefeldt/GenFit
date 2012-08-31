
#include "RKTools.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include "stdlib.h"
#include <string.h>

void RKTools::J_pMTxcov5xJ_pM(const M5x7& J_pM, const M5x5& cov5, M7x7& out7){

  // it is assumed that J_pM is only non-zero here:
  // [3*7+0]
  // [3*7+1]
  // [3*7+2]

  // [4*7+2]
  // [4*7+2]
  // [4*7+2]

  // [6] = 1

  // [1*7+3]
  // [1*7+4]
  // [1*7+5]

  // [2*7+3]
  // [2*7+4]
  // [2*7+5]

  double JTC0  = J_pM[21] * cov5[18] + J_pM[28] * cov5[23];
  double JTC1  = J_pM[21] * cov5[23] + J_pM[28] * cov5[24];
  double JTC2  = J_pM[21] * cov5[16] + J_pM[28] * cov5[21];
  double JTC3  = J_pM[21] * cov5[17] + J_pM[28] * cov5[22];
  double JTC4  = J_pM[22] * cov5[18] + J_pM[29] * cov5[23];
  double JTC5  = J_pM[22] * cov5[23] + J_pM[29] * cov5[24];
  double JTC6  = J_pM[22] * cov5[16] + J_pM[29] * cov5[21];
  double JTC7  = J_pM[22] * cov5[17] + J_pM[29] * cov5[22];
  double JTC8  = J_pM[23] * cov5[18] + J_pM[30] * cov5[23];
  double JTC9  = J_pM[23] * cov5[23] + J_pM[30] * cov5[24];
  double JTC10 = J_pM[23] * cov5[16] + J_pM[30] * cov5[21];
  double JTC11 = J_pM[23] * cov5[17] + J_pM[30] * cov5[22];
  double JTC12 = J_pM[10] * cov5[6]  + J_pM[17] * cov5[11];
  double JTC13 = J_pM[10] * cov5[11] + J_pM[17] * cov5[12];
  double JTC14 = J_pM[11] * cov5[6]  + J_pM[18] * cov5[11];
  double JTC15 = J_pM[11] * cov5[11] + J_pM[18] * cov5[12];

  // loops are vectorizable by the compiler!
  for (int i=0; i<3; ++i) out7[i]  = JTC0 * J_pM[21+i] + JTC1 * J_pM[28+i];
  for (int i=0; i<3; ++i) out7[3+i]  = JTC2 * J_pM[10+i] + JTC3 * J_pM[17+i];
  out7[6]  =  J_pM[21] * cov5[15] + J_pM[28] * cov5[20];

  for (int i=0; i<2; ++i) out7[8+i]  = JTC4 * J_pM[22+i] + JTC5 * J_pM[29+i];
  for (int i=0; i<3; ++i) out7[10+i] = JTC6 * J_pM[10+i] + JTC7 * J_pM[17+i];
  out7[13] = J_pM[22] * cov5[15] + J_pM[29] * cov5[20];

  out7[16] = JTC8 * J_pM[23] + JTC9 * J_pM[30];
  for (int i=0; i<3; ++i) out7[17+i] = JTC10 * J_pM[10+i] + JTC11 * J_pM[17+i];
  out7[20] = J_pM[23] * cov5[15] + J_pM[30] * cov5[20];

  for (int i=0; i<3; ++i) out7[24+i] = JTC12 * J_pM[10+i] + JTC13 * J_pM[17+i];
  out7[27] = J_pM[10] * cov5[5] + J_pM[17] * cov5[10];

  for (int i=0; i<2; ++i) out7[32+i] = JTC14 * J_pM[11+i] + JTC15 * J_pM[18+i];
  out7[34] = J_pM[11] * cov5[5] + J_pM[18] * cov5[10];

  out7[40] = (J_pM[12] * cov5[6] + J_pM[19] * cov5[11]) * J_pM[12] + (J_pM[12] * cov5[11] + J_pM[19] * cov5[12]) * J_pM[19];
  out7[41] = J_pM[12] * cov5[5] + J_pM[19] * cov5[10];

  out7[48] = cov5[0];

  // symmetric part
  out7[7]  = out7[1];
  out7[14] = out7[2];  out7[15] = out7[9];
  out7[21] = out7[3];  out7[22] = out7[10];  out7[23] = out7[17];
  out7[28] = out7[4];  out7[29] = out7[11];  out7[30] = out7[18];  out7[31] = out7[25];
  out7[35] = out7[5];  out7[36] = out7[12];  out7[37] = out7[19];  out7[38] = out7[26];  out7[39] = out7[33];
  out7[42] = out7[6];  out7[43] = out7[13];  out7[44] = out7[20];  out7[45] = out7[27];  out7[46] = out7[34];  out7[47] = out7[41];

}


void RKTools::J_pMTxcov5xJ_pM(const M5x6& J_pM, const M5x5& cov5, M6x6& out6){

  // it is assumed that J_pM is only non-zero here:
  // [3]
  // [4]
  // [5]

  // [1*7+3]
  // [1*7+4]
  // [1*7+5]

  // [2*7+3]
  // [2*7+4]
  // [2*7+5]

  // [3*7+0]
  // [3*7+1]
  // [3*7+2]

  // [4*7+0]
  // [4*7+1]
  // [4*7+2]

  double JTC0  = J_pM[18] * cov5[15+3] + J_pM[24] * cov5[20+3];
  double JTC1  = J_pM[18] * cov5[20+3] + J_pM[24] * cov5[20+4];
  double JTC2  = J_pM[18] * cov5[15] + J_pM[24] * cov5[20];
  double JTC3  = J_pM[18] * cov5[15+1] + J_pM[24] * cov5[20+1];
  double JTC4  = J_pM[18] * cov5[15+2] + J_pM[24] * cov5[20+2];
  double JTC5  = J_pM[18+1] * cov5[15+3] + J_pM[24+1] * cov5[20+3];
  double JTC6  = J_pM[18+1] * cov5[20+3] + J_pM[24+1] * cov5[20+4];
  double JTC7  = J_pM[18+1] * cov5[15] + J_pM[24+1] * cov5[20];
  double JTC8  = J_pM[18+1] * cov5[15+1] + J_pM[24+1] * cov5[20+1];
  double JTC9  = J_pM[18+1] * cov5[15+2] + J_pM[24+1] * cov5[20+2];
  double JTC10 = J_pM[18+2] * cov5[15] + J_pM[24+2] * cov5[20];
  double JTC11 = J_pM[18+2] * cov5[15+1] + J_pM[24+2] * cov5[20+1];
  double JTC12 = J_pM[18+2] * cov5[15+2] + J_pM[24+2] * cov5[20+2];
  double JTC13 = J_pM[3] * cov5[0*5] + J_pM[6+3] * cov5[5] + J_pM[12+3] * cov5[10];
  double JTC14 = J_pM[3] * cov5[5] + J_pM[6+3] * cov5[5+1] + J_pM[12+3] * cov5[10+1];
  double JTC15 = J_pM[3] * cov5[10] + J_pM[6+3] * cov5[10+1] + J_pM[12+3] * cov5[10+2];
  double JTC16 = J_pM[4] * cov5[0*5] + J_pM[6+4] * cov5[5] + J_pM[12+4] * cov5[10];
  double JTC17 = J_pM[4] * cov5[5] + J_pM[6+4] * cov5[5+1] + J_pM[12+4] * cov5[10+1];
  double JTC18 = J_pM[4] * cov5[10] + J_pM[6+4] * cov5[10+1] + J_pM[12+4] * cov5[10+2];

  // loops are vectorizable by the compiler!
  for (int i=0; i<3; ++i) out6[i] = JTC0 * J_pM[18+i] + JTC1 * J_pM[24+i];
  for (int i=0; i<3; ++i) out6[3+i] = JTC2 * J_pM[3+i] + JTC3 * J_pM[9+i] + JTC4 * J_pM[15+i];

  for (int i=0; i<2; ++i) out6[7+i] = JTC5 * J_pM[19+i] + JTC6 * J_pM[25+i];
  for (int i=0; i<3; ++i) out6[9+i] = JTC7 * J_pM[3+i] + JTC8 * J_pM[9+i] + JTC9 * J_pM[15+i];

  out6[12+2] = (J_pM[18+2] * cov5[15+3] + J_pM[24+2] * cov5[20+3]) * J_pM[18+2] + (J_pM[18+2] * cov5[20+3] + J_pM[24+2] * cov5[20+4]) * J_pM[24+2];
  for (int i=0; i<3; ++i) out6[15+i] = JTC10 * J_pM[3+i] + JTC11 * J_pM[9+i] + JTC12 * J_pM[15+i];

  for (int i=0; i<3; ++i) out6[21+i] = JTC13 * J_pM[3+i] + JTC14 * J_pM[9+i] + JTC15 * J_pM[15+i];

  for (int i=0; i<3; ++i) out6[28+i] = JTC16 * J_pM[4+i] + JTC17 * J_pM[10+i] + JTC18 * J_pM[16+i];

  out6[30+5] = (J_pM[5] * cov5[0*5] + J_pM[6+5] * cov5[5] + J_pM[12+5] * cov5[10]) * J_pM[5] + (J_pM[5] * cov5[5] + J_pM[6+5] * cov5[5+1] + J_pM[12+5] * cov5[10+1]) * J_pM[6+5] + (J_pM[5] * cov5[10] + J_pM[6+5] * cov5[10+1] + J_pM[12+5] * cov5[10+2]) * J_pM[12+5];

  // symmetric part
  out6[6] = out6[1];
  out6[12] = out6[2];  out6[12+1] = out6[6+2];
  out6[18] = out6[3];  out6[18+1] = out6[6+3];  out6[18+2] = out6[12+3];
  out6[24] = out6[4];  out6[24+1] = out6[6+4];  out6[24+2] = out6[12+4];  out6[24+3] = out6[18+4];
  out6[30] = out6[5];  out6[30+1] = out6[6+5];  out6[30+2] = out6[12+5];  out6[30+3] = out6[18+5];  out6[30+4] = out6[24+5];

}


void RKTools::J_MpTxcov7xJ_Mp(const M7x5& J_Mp, const M7x7& cov7, M5x5& out5){

  // it is assumed that J_Mp is only non-zero here:
  // [3*7+1]
  // [4*7+1]
  // [5*7+1]

  // [3*7+2]
  // [4*7+2]
  // [5*7+2]

  // [6*7+0] = 1

  // [3]
  // [1*7+3]
  // [2*7+3]

  // [4]
  // [1*7+4]
  // [2*7+4]

  double JTC0  = (J_Mp[16] * cov7[24] + J_Mp[21] * cov7[31] + J_Mp[26] * cov7[38]);
  double JTC1  = (J_Mp[16] * cov7[31] + J_Mp[21] * cov7[32] + J_Mp[26] * cov7[39]);
  double JTC2  = (J_Mp[16] * cov7[38] + J_Mp[21] * cov7[39] + J_Mp[26] * cov7[40]);
  double JTC3  = (J_Mp[16] * cov7[21] + J_Mp[21] * cov7[28] + J_Mp[26] * cov7[35]);
  double JTC4  = (J_Mp[16] * cov7[22] + J_Mp[21] * cov7[29] + J_Mp[26] * cov7[36]);
  double JTC5  = (J_Mp[16] * cov7[23] + J_Mp[21] * cov7[30] + J_Mp[26] * cov7[37]);
  double JTC6  = (J_Mp[17] * cov7[21] + J_Mp[22] * cov7[28] + J_Mp[27] * cov7[35]);
  double JTC7  = (J_Mp[17] * cov7[22] + J_Mp[22] * cov7[29] + J_Mp[27] * cov7[36]);
  double JTC8  = (J_Mp[17] * cov7[23] + J_Mp[22] * cov7[30] + J_Mp[27] * cov7[37]);
  double JTC9  = (J_Mp[3] * cov7[0] + J_Mp[8] * cov7[7] + J_Mp[13] * cov7[14]);
  double JTC10 = (J_Mp[3] * cov7[7] + J_Mp[8] * cov7[8] + J_Mp[13] * cov7[15]);
  double JTC11 = (J_Mp[3] * cov7[14] + J_Mp[8] * cov7[15] + J_Mp[13] * cov7[16]);

  out5[0] = cov7[48];
  out5[1] = J_Mp[16] * cov7[45] + J_Mp[21] * cov7[46] + J_Mp[26] * cov7[47];
  out5[2] = J_Mp[17] * cov7[45] + J_Mp[22] * cov7[46] + J_Mp[27] * cov7[47];
  out5[3] = J_Mp[3] * cov7[42] + J_Mp[8] * cov7[43] + J_Mp[13] * cov7[44];
  out5[4] = J_Mp[4] * cov7[42] + J_Mp[9] * cov7[43] + J_Mp[14] * cov7[44];

  // loops are vectorizable by the compiler!
  for (int i=0; i<2; ++i) out5[6+i] = JTC0 * J_Mp[16+i] + JTC1 * J_Mp[21+i] + JTC2 * J_Mp[26+i];
  for (int i=0; i<2; ++i) out5[8+i] = JTC3 * J_Mp[3+i] + JTC4 * J_Mp[8+i] + JTC5 * J_Mp[13+i];

  out5[12] = (J_Mp[17] * cov7[24] + J_Mp[22] * cov7[31] + J_Mp[27] * cov7[38]) * J_Mp[17] + (J_Mp[17] * cov7[31] + J_Mp[22] * cov7[32] + J_Mp[27] * cov7[39]) * J_Mp[22] + (J_Mp[17] * cov7[38] + J_Mp[22] * cov7[39] + J_Mp[27] * cov7[40]) * J_Mp[27];
  for (int i=0; i<2; ++i) out5[13+i] = JTC6 * J_Mp[3+i] + JTC7 * J_Mp[8+i] + JTC8 * J_Mp[13+i];

  for (int i=0; i<2; ++i) out5[18+i] = JTC9 * J_Mp[3+i] + JTC10 * J_Mp[8+i] + JTC11 * J_Mp[13+i];

  out5[24] = (J_Mp[4] * cov7[0] + J_Mp[9] * cov7[7] + J_Mp[14] * cov7[14]) * J_Mp[4] + (J_Mp[4] * cov7[7] + J_Mp[9] * cov7[8] + J_Mp[14] * cov7[15]) * J_Mp[9] + (J_Mp[4] * cov7[14] + J_Mp[9] * cov7[15] + J_Mp[14] * cov7[16]) * J_Mp[14];

  // symmetric part
  out5[5] = out5[1];
  out5[10] = out5[2];  out5[11] = out5[7];
  out5[15] = out5[3];  out5[16] = out5[8];  out5[17] = out5[13];
  out5[20] = out5[4];  out5[21] = out5[9];  out5[22] = out5[14];  out5[23] = out5[19];

}


void RKTools::J_MpTxcov6xJ_Mp(const M6x5& J_Mp, const M6x6& cov6, M5x5& out5){

  // it is assumed that J_Mp is only non-zero here:
  // [3]
  // [1*7+3]
  // [2*7+3]

  // [4]
  // [1*7+4]
  // [2*7+4]

  // [3*7+0]
  // [4*7+0]
  // [5*7+0]

  // [3*7+1]
  // [4*7+1]
  // [5*7+1]

  // [3*7+2]
  // [4*7+2]
  // [5*7+2]

  double JTC0  = (J_Mp[15] * cov6[18+3] + J_Mp[20] * cov6[24+3] + J_Mp[25] * cov6[30+3]);
  double JTC1  = (J_Mp[15] * cov6[24+3] + J_Mp[20] * cov6[24+4] + J_Mp[25] * cov6[30+4]);
  double JTC2  = (J_Mp[15] * cov6[30+3] + J_Mp[20] * cov6[30+4] + J_Mp[25] * cov6[30+5]);
  double JTC3  = (J_Mp[15] * cov6[18] + J_Mp[20] * cov6[24] + J_Mp[25] * cov6[30]);
  double JTC4  = (J_Mp[15] * cov6[18+1] + J_Mp[20] * cov6[24+1] + J_Mp[25] * cov6[30+1]);
  double JTC5  = (J_Mp[15] * cov6[18+2] + J_Mp[20] * cov6[24+2] + J_Mp[25] * cov6[30+2]);
  double JTC6  = (J_Mp[15+1] * cov6[18+3] + J_Mp[20+1] * cov6[24+3] + J_Mp[25+1] * cov6[30+3]);
  double JTC7  = (J_Mp[15+1] * cov6[24+3] + J_Mp[20+1] * cov6[24+4] + J_Mp[25+1] * cov6[30+4]);
  double JTC8  = (J_Mp[15+1] * cov6[30+3] + J_Mp[20+1] * cov6[30+4] + J_Mp[25+1] * cov6[30+5]);
  double JTC9  = (J_Mp[15+1] * cov6[18] + J_Mp[20+1] * cov6[24] + J_Mp[25+1] * cov6[30]);
  double JTC10 = (J_Mp[15+1] * cov6[18+1] + J_Mp[20+1] * cov6[24+1] + J_Mp[25+1] * cov6[30+1]);
  double JTC11 = (J_Mp[15+1] * cov6[18+2] + J_Mp[20+1] * cov6[24+2] + J_Mp[25+1] * cov6[30+2]);
  double JTC12 = (J_Mp[15+2] * cov6[18] + J_Mp[20+2] * cov6[24] + J_Mp[25+2] * cov6[30]);
  double JTC13 = (J_Mp[15+2] * cov6[18+1] + J_Mp[20+2] * cov6[24+1] + J_Mp[25+2] * cov6[30+1]);
  double JTC14 = (J_Mp[15+2] * cov6[18+2] + J_Mp[20+2] * cov6[24+2] + J_Mp[25+2] * cov6[30+2]);
  double JTC15 = (J_Mp[3] * cov6[0] + J_Mp[5+3] * cov6[6] + J_Mp[10+3] * cov6[12]);
  double JTC16 = (J_Mp[3] * cov6[6] + J_Mp[5+3] * cov6[6+1] + J_Mp[10+3] * cov6[12+1]);
  double JTC17 = (J_Mp[3] * cov6[12] + J_Mp[5+3] * cov6[12+1] + J_Mp[10+3] * cov6[12+2]);

  // loops are vectorizable by the compiler!
  for (int i=0; i<3; ++i) out5[i] = JTC0 * J_Mp[15+i] + JTC1 * J_Mp[20+i] + JTC2 * J_Mp[25+i];
  for (int i=0; i<2; ++i) out5[3+i] = JTC3 * J_Mp[3+i] + JTC4 * J_Mp[8+i] + JTC5 * J_Mp[13+i];

  for (int i=0; i<2; ++i) out5[6+i] = JTC6 * J_Mp[16+i] + JTC7 * J_Mp[21+i] + JTC8 * J_Mp[26+i];
  for (int i=0; i<2; ++i) out5[8+i] = JTC9 * J_Mp[3+i] + JTC10 * J_Mp[8+i] + JTC11 * J_Mp[13+i];

  out5[10+2] = (J_Mp[15+2] * cov6[18+3] + J_Mp[20+2] * cov6[24+3] + J_Mp[25+2] * cov6[30+3]) * J_Mp[15+2] + (J_Mp[15+2] * cov6[24+3] + J_Mp[20+2] * cov6[24+4] + J_Mp[25+2] * cov6[30+4]) * J_Mp[20+2] + (J_Mp[15+2] * cov6[30+3] + J_Mp[20+2] * cov6[30+4] + J_Mp[25+2] * cov6[30+5]) * J_Mp[25+2];
  for (int i=0; i<2; ++i) out5[13+i] = JTC12 * J_Mp[3+i] + JTC13 * J_Mp[8+i] + JTC14 * J_Mp[13+i];

  for (int i=0; i<2; ++i) out5[18+i] = JTC15 * J_Mp[3+i] + JTC16 * J_Mp[8+i] + JTC17 * J_Mp[13+i];

  out5[20+4] = (J_Mp[4] * cov6[0] + J_Mp[5+4] * cov6[6] + J_Mp[10+4] * cov6[12]) * J_Mp[4] + (J_Mp[4] * cov6[6] + J_Mp[5+4] * cov6[6+1] + J_Mp[10+4] * cov6[12+1]) * J_Mp[5+4] + (J_Mp[4] * cov6[12] + J_Mp[5+4] * cov6[12+1] + J_Mp[10+4] * cov6[12+2]) * J_Mp[10+4];

  // symmetric part
  out5[5] = out5[1];
  out5[10] = out5[2];  out5[10+1] = out5[5+2];
  out5[15] = out5[3];  out5[15+1] = out5[5+3];  out5[15+2] = out5[10+3];
  out5[20] = out5[4];  out5[20+1] = out5[5+4];  out5[20+2] = out5[10+4];  out5[20+3] = out5[15+4];

}


void RKTools::J_MMTxcov7xJ_MM(const M7x7& J_MM, const M7x7& cov7, M7x7& out7){

  // it is assumed that the last column of J_MM is [0,0,0,0,0,0,1]

  double JTC0  = J_MM[0] * cov7[0] + J_MM[7] * cov7[7] + J_MM[14] * cov7[14] + J_MM[21] * cov7[21] + J_MM[28] * cov7[28] + J_MM[35] * cov7[35] + J_MM[42] * cov7[42];
  double JTC1  = J_MM[0] * cov7[7] + J_MM[7] * cov7[7+1] + J_MM[14] * cov7[14+1] + J_MM[21] * cov7[21+1] + J_MM[28] * cov7[28+1] + J_MM[35] * cov7[35+1] + J_MM[42] * cov7[42+1];
  double JTC2  = J_MM[0] * cov7[14] + J_MM[7] * cov7[14+1] + J_MM[14] * cov7[14+2] + J_MM[21] * cov7[21+2] + J_MM[28] * cov7[28+2] + J_MM[35] * cov7[35+2] + J_MM[42] * cov7[42+2];
  double JTC3  = J_MM[0] * cov7[21] + J_MM[7] * cov7[21+1] + J_MM[14] * cov7[21+2] + J_MM[21] * cov7[21+3] + J_MM[28] * cov7[28+3] + J_MM[35] * cov7[35+3] + J_MM[42] * cov7[42+3];
  double JTC4  = J_MM[0] * cov7[28] + J_MM[7] * cov7[28+1] + J_MM[14] * cov7[28+2] + J_MM[21] * cov7[28+3] + J_MM[28] * cov7[28+4] + J_MM[35] * cov7[35+4] + J_MM[42] * cov7[42+4];
  double JTC5  = J_MM[0] * cov7[35] + J_MM[7] * cov7[35+1] + J_MM[14] * cov7[35+2] + J_MM[21] * cov7[35+3] + J_MM[28] * cov7[35+4] + J_MM[35] * cov7[35+5] + J_MM[42] * cov7[42+5];
  double JTC6  = J_MM[0] * cov7[42] + J_MM[7] * cov7[42+1] + J_MM[14] * cov7[42+2] + J_MM[21] * cov7[42+3] + J_MM[28] * cov7[42+4] + J_MM[35] * cov7[42+5] + J_MM[42] * cov7[42+6];

  double JTC7  = J_MM[1] * cov7[0] + J_MM[7+1] * cov7[7] + J_MM[14+1] * cov7[14] + J_MM[21+1] * cov7[21] + J_MM[28+1] * cov7[28] + J_MM[35+1] * cov7[35] + J_MM[42+1] * cov7[42];
  double JTC8  = J_MM[1] * cov7[7] + J_MM[7+1] * cov7[7+1] + J_MM[14+1] * cov7[14+1] + J_MM[21+1] * cov7[21+1] + J_MM[28+1] * cov7[28+1] + J_MM[35+1] * cov7[35+1] + J_MM[42+1] * cov7[42+1];
  double JTC9  = J_MM[1] * cov7[14] + J_MM[7+1] * cov7[14+1] + J_MM[14+1] * cov7[14+2] + J_MM[21+1] * cov7[21+2] + J_MM[28+1] * cov7[28+2] + J_MM[35+1] * cov7[35+2] + J_MM[42+1] * cov7[42+2];
  double JTC10 = J_MM[1] * cov7[21] + J_MM[7+1] * cov7[21+1] + J_MM[14+1] * cov7[21+2] + J_MM[21+1] * cov7[21+3] + J_MM[28+1] * cov7[28+3] + J_MM[35+1] * cov7[35+3] + J_MM[42+1] * cov7[42+3];
  double JTC11 = J_MM[1] * cov7[28] + J_MM[7+1] * cov7[28+1] + J_MM[14+1] * cov7[28+2] + J_MM[21+1] * cov7[28+3] + J_MM[28+1] * cov7[28+4] + J_MM[35+1] * cov7[35+4] + J_MM[42+1] * cov7[42+4];
  double JTC12 = J_MM[1] * cov7[35] + J_MM[7+1] * cov7[35+1] + J_MM[14+1] * cov7[35+2] + J_MM[21+1] * cov7[35+3] + J_MM[28+1] * cov7[35+4] + J_MM[35+1] * cov7[35+5] + J_MM[42+1] * cov7[42+5];
  double JTC13 = J_MM[1] * cov7[42] + J_MM[7+1] * cov7[42+1] + J_MM[14+1] * cov7[42+2] + J_MM[21+1] * cov7[42+3] + J_MM[28+1] * cov7[42+4] + J_MM[35+1] * cov7[42+5] + J_MM[42+1] * cov7[42+6];

  double JTC14 = J_MM[2] * cov7[0] + J_MM[7+2] * cov7[7] + J_MM[14+2] * cov7[14] + J_MM[21+2] * cov7[21] + J_MM[28+2] * cov7[28] + J_MM[35+2] * cov7[35] + J_MM[42+2] * cov7[42];
  double JTC15 = J_MM[2] * cov7[7] + J_MM[7+2] * cov7[7+1] + J_MM[14+2] * cov7[14+1] + J_MM[21+2] * cov7[21+1] + J_MM[28+2] * cov7[28+1] + J_MM[35+2] * cov7[35+1] + J_MM[42+2] * cov7[42+1];
  double JTC16 = J_MM[2] * cov7[14] + J_MM[7+2] * cov7[14+1] + J_MM[14+2] * cov7[14+2] + J_MM[21+2] * cov7[21+2] + J_MM[28+2] * cov7[28+2] + J_MM[35+2] * cov7[35+2] + J_MM[42+2] * cov7[42+2];
  double JTC17 = J_MM[2] * cov7[21] + J_MM[7+2] * cov7[21+1] + J_MM[14+2] * cov7[21+2] + J_MM[21+2] * cov7[21+3] + J_MM[28+2] * cov7[28+3] + J_MM[35+2] * cov7[35+3] + J_MM[42+2] * cov7[42+3];
  double JTC18 = J_MM[2] * cov7[28] + J_MM[7+2] * cov7[28+1] + J_MM[14+2] * cov7[28+2] + J_MM[21+2] * cov7[28+3] + J_MM[28+2] * cov7[28+4] + J_MM[35+2] * cov7[35+4] + J_MM[42+2] * cov7[42+4];
  double JTC19 = J_MM[2] * cov7[35] + J_MM[7+2] * cov7[35+1] + J_MM[14+2] * cov7[35+2] + J_MM[21+2] * cov7[35+3] + J_MM[28+2] * cov7[35+4] + J_MM[35+2] * cov7[35+5] + J_MM[42+2] * cov7[42+5];
  double JTC20 = J_MM[2] * cov7[42] + J_MM[7+2] * cov7[42+1] + J_MM[14+2] * cov7[42+2] + J_MM[21+2] * cov7[42+3] + J_MM[28+2] * cov7[42+4] + J_MM[35+2] * cov7[42+5] + J_MM[42+2] * cov7[42+6];

  double JTC21 = J_MM[3] * cov7[0] + J_MM[7+3] * cov7[7] + J_MM[14+3] * cov7[14] + J_MM[21+3] * cov7[21] + J_MM[28+3] * cov7[28] + J_MM[35+3] * cov7[35] + J_MM[42+3] * cov7[42];
  double JTC22 = J_MM[3] * cov7[7] + J_MM[7+3] * cov7[7+1] + J_MM[14+3] * cov7[14+1] + J_MM[21+3] * cov7[21+1] + J_MM[28+3] * cov7[28+1] + J_MM[35+3] * cov7[35+1] + J_MM[42+3] * cov7[42+1];
  double JTC23 = J_MM[3] * cov7[14] + J_MM[7+3] * cov7[14+1] + J_MM[14+3] * cov7[14+2] + J_MM[21+3] * cov7[21+2] + J_MM[28+3] * cov7[28+2] + J_MM[35+3] * cov7[35+2] + J_MM[42+3] * cov7[42+2];
  double JTC24 = J_MM[3] * cov7[21] + J_MM[7+3] * cov7[21+1] + J_MM[14+3] * cov7[21+2] + J_MM[21+3] * cov7[21+3] + J_MM[28+3] * cov7[28+3] + J_MM[35+3] * cov7[35+3] + J_MM[42+3] * cov7[42+3];
  double JTC25 = J_MM[3] * cov7[28] + J_MM[7+3] * cov7[28+1] + J_MM[14+3] * cov7[28+2] + J_MM[21+3] * cov7[28+3] + J_MM[28+3] * cov7[28+4] + J_MM[35+3] * cov7[35+4] + J_MM[42+3] * cov7[42+4];
  double JTC26 = J_MM[3] * cov7[35] + J_MM[7+3] * cov7[35+1] + J_MM[14+3] * cov7[35+2] + J_MM[21+3] * cov7[35+3] + J_MM[28+3] * cov7[35+4] + J_MM[35+3] * cov7[35+5] + J_MM[42+3] * cov7[42+5];
  double JTC27 = J_MM[3] * cov7[42] + J_MM[7+3] * cov7[42+1] + J_MM[14+3] * cov7[42+2] + J_MM[21+3] * cov7[42+3] + J_MM[28+3] * cov7[42+4] + J_MM[35+3] * cov7[42+5] + J_MM[42+3] * cov7[42+6];

  double JTC28 = J_MM[4] * cov7[0] + J_MM[7+4] * cov7[7] + J_MM[14+4] * cov7[14] + J_MM[21+4] * cov7[21] + J_MM[28+4] * cov7[28] + J_MM[35+4] * cov7[35] + J_MM[42+4] * cov7[42];
  double JTC29 = J_MM[4] * cov7[7] + J_MM[7+4] * cov7[7+1] + J_MM[14+4] * cov7[14+1] + J_MM[21+4] * cov7[21+1] + J_MM[28+4] * cov7[28+1] + J_MM[35+4] * cov7[35+1] + J_MM[42+4] * cov7[42+1];
  double JTC30 = J_MM[4] * cov7[14] + J_MM[7+4] * cov7[14+1] + J_MM[14+4] * cov7[14+2] + J_MM[21+4] * cov7[21+2] + J_MM[28+4] * cov7[28+2] + J_MM[35+4] * cov7[35+2] + J_MM[42+4] * cov7[42+2];
  double JTC31 = J_MM[4] * cov7[21] + J_MM[7+4] * cov7[21+1] + J_MM[14+4] * cov7[21+2] + J_MM[21+4] * cov7[21+3] + J_MM[28+4] * cov7[28+3] + J_MM[35+4] * cov7[35+3] + J_MM[42+4] * cov7[42+3];
  double JTC32 = J_MM[4] * cov7[28] + J_MM[7+4] * cov7[28+1] + J_MM[14+4] * cov7[28+2] + J_MM[21+4] * cov7[28+3] + J_MM[28+4] * cov7[28+4] + J_MM[35+4] * cov7[35+4] + J_MM[42+4] * cov7[42+4];
  double JTC33 = J_MM[4] * cov7[35] + J_MM[7+4] * cov7[35+1] + J_MM[14+4] * cov7[35+2] + J_MM[21+4] * cov7[35+3] + J_MM[28+4] * cov7[35+4] + J_MM[35+4] * cov7[35+5] + J_MM[42+4] * cov7[42+5];
  double JTC34 = J_MM[4] * cov7[42] + J_MM[7+4] * cov7[42+1] + J_MM[14+4] * cov7[42+2] + J_MM[21+4] * cov7[42+3] + J_MM[28+4] * cov7[42+4] + J_MM[35+4] * cov7[42+5] + J_MM[42+4] * cov7[42+6];

  // last row
  out7[6]    =  JTC6;
  out7[7+6]  =  JTC13;
  out7[14+6] =  JTC20;
  out7[21+6] =  JTC27;
  out7[28+6] =  JTC34;
  out7[35+6] =  J_MM[5] * cov7[42] + J_MM[7+5] * cov7[42+1] + J_MM[14+5] * cov7[42+2] + J_MM[21+5] * cov7[42+3] + J_MM[28+5] * cov7[42+4] + J_MM[35+5] * cov7[42+5] + J_MM[42+5] * cov7[42+6];
  out7[42+6] = cov7[42+6];

  // loops are vectorizable by the compiler!
  for (int i=0; i<6; ++i) out7[i]    = JTC0  * J_MM[i] + JTC1  * J_MM[7+i] + JTC2  * J_MM[14+i] + JTC3  * J_MM[21+i] + JTC4  * J_MM[28+i] + JTC5  * J_MM[35+i] + JTC6  * J_MM[42+i];
  for (int i=1; i<6; ++i) out7[7+i]  = JTC7  * J_MM[i] + JTC8  * J_MM[7+i] + JTC9  * J_MM[14+i] + JTC10 * J_MM[21+i] + JTC11 * J_MM[28+i] + JTC12 * J_MM[35+i] + JTC13 * J_MM[42+i];
  for (int i=2; i<6; ++i) out7[14+i] = JTC14 * J_MM[i] + JTC15 * J_MM[7+i] + JTC16 * J_MM[14+i] + JTC17 * J_MM[21+i] + JTC18 * J_MM[28+i] + JTC19 * J_MM[35+i] + JTC20 * J_MM[42+i];
  for (int i=3; i<6; ++i) out7[21+i] = JTC21 * J_MM[i] + JTC22 * J_MM[7+i] + JTC23 * J_MM[14+i] + JTC24 * J_MM[21+i] + JTC25 * J_MM[28+i] + JTC26 * J_MM[35+i] + JTC27 * J_MM[42+i];
  for (int i=4; i<6; ++i) out7[28+i] = JTC28 * J_MM[i] + JTC29 * J_MM[7+i] + JTC30 * J_MM[14+i] + JTC31 * J_MM[21+i] + JTC32 * J_MM[28+i] + JTC33 * J_MM[35+i] + JTC34 * J_MM[42+i];
  out7[35+5] = (J_MM[5] * cov7[0] + J_MM[7+5] * cov7[7] + J_MM[14+5] * cov7[14] + J_MM[21+5] * cov7[21] + J_MM[28+5] * cov7[28] + J_MM[35+5] * cov7[35] + J_MM[42+5] * cov7[42]) * J_MM[5] + (J_MM[5] * cov7[7] + J_MM[7+5] * cov7[7+1] + J_MM[14+5] * cov7[14+1] + J_MM[21+5] * cov7[21+1] + J_MM[28+5] * cov7[28+1] + J_MM[35+5] * cov7[35+1] + J_MM[42+5] * cov7[42+1]) * J_MM[7+5] + (J_MM[5] * cov7[14] + J_MM[7+5] * cov7[14+1] + J_MM[14+5] * cov7[14+2] + J_MM[21+5] * cov7[21+2] + J_MM[28+5] * cov7[28+2] + J_MM[35+5] * cov7[35+2] + J_MM[42+5] * cov7[42+2]) * J_MM[14+5] + (J_MM[5] * cov7[21] + J_MM[7+5] * cov7[21+1] + J_MM[14+5] * cov7[21+2] + J_MM[21+5] * cov7[21+3] + J_MM[28+5] * cov7[28+3] + J_MM[35+5] * cov7[35+3] + J_MM[42+5] * cov7[42+3]) * J_MM[21+5] + (J_MM[5] * cov7[28] + J_MM[7+5] * cov7[28+1] + J_MM[14+5] * cov7[28+2] + J_MM[21+5] * cov7[28+3] + J_MM[28+5] * cov7[28+4] + J_MM[35+5] * cov7[35+4] + J_MM[42+5] * cov7[42+4]) * J_MM[28+5] + (J_MM[5] * cov7[35] + J_MM[7+5] * cov7[35+1] + J_MM[14+5] * cov7[35+2] + J_MM[21+5] * cov7[35+3] + J_MM[28+5] * cov7[35+4] + J_MM[35+5] * cov7[35+5] + J_MM[42+5] * cov7[42+5]) * J_MM[35+5] + (J_MM[5] * cov7[42] + J_MM[7+5] * cov7[42+1] + J_MM[14+5] * cov7[42+2] + J_MM[21+5] * cov7[42+3] + J_MM[28+5] * cov7[42+4] + J_MM[35+5] * cov7[42+5] + J_MM[42+5] * cov7[42+6]) * J_MM[42+5];

  // symmetric part
  out7[7]  = out7[1];
  out7[14] = out7[2];  out7[14+1] = out7[9];
  out7[21] = out7[3];  out7[21+1] = out7[10];  out7[21+2] = out7[17];
  out7[28] = out7[4];  out7[28+1] = out7[11];  out7[28+2] = out7[18];  out7[28+3] = out7[25];
  out7[35] = out7[5];  out7[35+1] = out7[12];  out7[35+2] = out7[19];  out7[35+3] = out7[26];  out7[35+4] = out7[33];
  out7[42] = out7[6];  out7[42+1] = out7[13];  out7[42+2] = out7[20];  out7[42+3] = out7[27];  out7[42+4] = out7[34];  out7[42+5] = out7[41];

}


void RKTools::J_MMxJ_MM(M7x7& J_MM, const M7x7& J_MM_old){

  // J and J_old are
  // 1 0 0 0 0 0 0
  // 0 1 0 0 0 0 0
  // 0 0 1 0 0 0 0
  // x x x x x x 0
  // x x x x x x 0
  // x x x x x x 0
  // x x x x x x x

  M7x7 J_MM_temp;
  memcpy(J_MM_temp, J_MM, 7*7*sizeof(double));

  /*J_MM[0] = 1;
  J_MM[1] = 0;
  J_MM[2] = 0;
  J_MM[3] = 0;
  J_MM[4] = 0;
  J_MM[5] = 0;
  J_MM[6] = 0;

  J_MM[1*7+0] = 0;
  J_MM[1*7+1] = 1;
  J_MM[1*7+2] = 0;
  J_MM[1*7+3] = 0;
  J_MM[1*7+4] = 0;
  J_MM[1*7+5] = 0;
  J_MM[1*7+6] = 0;

  J_MM[2*7+0] = 0;
  J_MM[2*7+1] = 0;
  J_MM[2*7+2] = 1;
  J_MM[2*7+3] = 0;
  J_MM[2*7+4] = 0;
  J_MM[2*7+5] = 0;
  J_MM[2*7+6] = 0;*/

  J_MM[21] = J_MM_old[21] + J_MM_old[21+3] * J_MM_temp[21] + J_MM_old[21+4] * J_MM_temp[28] + J_MM_old[21+5] * J_MM_temp[35];
  J_MM[21+1] = J_MM_old[21+1] + J_MM_old[21+3] * J_MM_temp[21+1] + J_MM_old[21+4] * J_MM_temp[28+1] + J_MM_old[21+5] * J_MM_temp[35+1];
  J_MM[21+2] = J_MM_old[21+2] + J_MM_old[21+3] * J_MM_temp[21+2] + J_MM_old[21+4] * J_MM_temp[28+2] + J_MM_old[21+5] * J_MM_temp[35+2];
  J_MM[21+3] = J_MM_old[21+3] * J_MM_temp[21+3] + J_MM_old[21+4] * J_MM_temp[28+3] + J_MM_old[21+5] * J_MM_temp[35+3];
  J_MM[21+4] = J_MM_old[21+3] * J_MM_temp[21+4] + J_MM_old[21+4] * J_MM_temp[28+4] + J_MM_old[21+5] * J_MM_temp[35+4];
  J_MM[21+5] = J_MM_old[21+3] * J_MM_temp[21+5] + J_MM_old[21+4] * J_MM_temp[28+5] + J_MM_old[21+5] * J_MM_temp[35+5];
  //J_MM[21+6] = 0;

  J_MM[28] = J_MM_old[28] + J_MM_old[28+3] * J_MM_temp[21] + J_MM_old[28+4] * J_MM_temp[28] + J_MM_old[28+5] * J_MM_temp[35];
  J_MM[28+1] = J_MM_old[28+1] + J_MM_old[28+3] * J_MM_temp[21+1] + J_MM_old[28+4] * J_MM_temp[28+1] + J_MM_old[28+5] * J_MM_temp[35+1];
  J_MM[28+2] = J_MM_old[28+2] + J_MM_old[28+3] * J_MM_temp[21+2] + J_MM_old[28+4] * J_MM_temp[28+2] + J_MM_old[28+5] * J_MM_temp[35+2];
  J_MM[28+3] = J_MM_old[28+3] * J_MM_temp[21+3] + J_MM_old[28+4] * J_MM_temp[28+3] + J_MM_old[28+5] * J_MM_temp[35+3];
  J_MM[28+4] = J_MM_old[28+3] * J_MM_temp[21+4] + J_MM_old[28+4] * J_MM_temp[28+4] + J_MM_old[28+5] * J_MM_temp[35+4];
  J_MM[28+5] = J_MM_old[28+3] * J_MM_temp[21+5] + J_MM_old[28+4] * J_MM_temp[28+5] + J_MM_old[28+5] * J_MM_temp[35+5];
  //J_MM[28+6] = 0;

  J_MM[35] = J_MM_old[35] + J_MM_old[35+3] * J_MM_temp[21] + J_MM_old[35+4] * J_MM_temp[28] + J_MM_old[35+5] * J_MM_temp[35] ;
  J_MM[35+1] = J_MM_old[35+1] + J_MM_old[35+3] * J_MM_temp[21+1] + J_MM_old[35+4] * J_MM_temp[28+1] + J_MM_old[35+5] * J_MM_temp[35+1];
  J_MM[35+2] = J_MM_old[35+2] + J_MM_old[35+3] * J_MM_temp[21+2] + J_MM_old[35+4] * J_MM_temp[28+2] + J_MM_old[35+5] * J_MM_temp[35+2];
  J_MM[35+3] = J_MM_old[35+3] * J_MM_temp[21+3] + J_MM_old[35+4] * J_MM_temp[28+3] + J_MM_old[35+5] * J_MM_temp[35+3];
  J_MM[35+4] = J_MM_old[35+3] * J_MM_temp[21+4] + J_MM_old[35+4] * J_MM_temp[28+4] + J_MM_old[35+5] * J_MM_temp[35+4];
  J_MM[35+5] = J_MM_old[35+3] * J_MM_temp[21+5] + J_MM_old[35+4] * J_MM_temp[28+5] + J_MM_old[35+5] * J_MM_temp[35+5];
  //J_MM[35+6] = 0;

  J_MM[42] = J_MM_old[42] + J_MM_old[42+3] * J_MM_temp[21] + J_MM_old[42+4] * J_MM_temp[28] + J_MM_old[42+5] * J_MM_temp[35] + J_MM_old[42+6] * J_MM_temp[42];
  J_MM[42+1] = J_MM_old[42+1] + J_MM_old[42+3] * J_MM_temp[21+1] + J_MM_old[42+4] * J_MM_temp[28+1] + J_MM_old[42+5] * J_MM_temp[35+1] + J_MM_old[42+6] * J_MM_temp[42+1];
  J_MM[42+2] = J_MM_old[42+2] + J_MM_old[42+3] * J_MM_temp[21+2] + J_MM_old[42+4] * J_MM_temp[28+2] + J_MM_old[42+5] * J_MM_temp[35+2] + J_MM_old[42+6] * J_MM_temp[42+2];
  J_MM[42+3] = J_MM_old[42+3] * J_MM_temp[21+3] + J_MM_old[42+4] * J_MM_temp[28+3] + J_MM_old[42+5] * J_MM_temp[35+3] + J_MM_old[42+6] * J_MM_temp[42+3];
  J_MM[42+4] = J_MM_old[42+3] * J_MM_temp[21+4] + J_MM_old[42+4] * J_MM_temp[28+4] + J_MM_old[42+5] * J_MM_temp[35+4] + J_MM_old[42+6] * J_MM_temp[42+4];
  J_MM[42+5] = J_MM_old[42+3] * J_MM_temp[21+5] + J_MM_old[42+4] * J_MM_temp[28+5] + J_MM_old[42+5] * J_MM_temp[35+5] + J_MM_old[42+6] * J_MM_temp[42+5];
  J_MM[42+6] = J_MM_old[42+6] * J_MM_temp[42+6];

}


void RKTools::printDim(const double* mat, unsigned int dimX, unsigned int dimY){

  std::cout << dimX << " x " << dimY << " matrix as follows: \n";
  for (unsigned int i=0; i< dimX; ++i){
    for (unsigned int j=0; j< dimY; ++j){
      printf("  %11.5g", mat[i*dimX+j]);
    }
    std::cout<<"\n";
  }
  std::cout<<"\n";

}
