/* MIT License
 *
 * Copyright (c) 2016-2022 INRIA, CMU and Microsoft Corporation
 * Copyright (c) 2022-2023 HACL* Contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "Hacl_Hash_SHA3_Simd256.h"

#include "internal/Hacl_Hash_SHA3_Scalar.h"
#include "libintvector.h"

void
Hacl_Hash_SHA3_Simd256_shake128(
  uint32_t inputByteLen,
  uint8_t *input0,
  uint8_t *input1,
  uint8_t *input2,
  uint8_t *input3,
  uint32_t outputByteLen,
  uint8_t *output0,
  uint8_t *output1,
  uint8_t *output2,
  uint8_t *output3
)
{
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  ib = { .fst = input0, .snd = { .fst = input1, .snd = { .fst = input2, .snd = input3 } } };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  rb = { .fst = output0, .snd = { .fst = output1, .snd = { .fst = output2, .snd = output3 } } };
  uint32_t rateInBytes = 168U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 s[25U] KRML_POST_ALIGN(32) = { 0U };
  for (uint32_t i0 = 0U; i0 < inputByteLen / rateInBytes; i0++)
  {
    uint8_t b00[256U] = { 0U };
    uint8_t b10[256U] = { 0U };
    uint8_t b20[256U] = { 0U };
    uint8_t b30[256U] = { 0U };
    K____uint8_t___uint8_t____K____uint8_t___uint8_t_
    b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
    uint8_t *b31 = ib.snd.snd.snd;
    uint8_t *b21 = ib.snd.snd.fst;
    uint8_t *b11 = ib.snd.fst;
    uint8_t *b01 = ib.fst;
    uint8_t *bl3 = b_.snd.snd.snd;
    uint8_t *bl2 = b_.snd.snd.fst;
    uint8_t *bl1 = b_.snd.fst;
    uint8_t *bl0 = b_.fst;
    memcpy(bl0, b01 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl1, b11 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl2, b21 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl3, b31 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    uint8_t *b3 = b_.snd.snd.snd;
    uint8_t *b2 = b_.snd.snd.fst;
    uint8_t *b1 = b_.snd.fst;
    uint8_t *b0 = b_.fst;
    ws[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0);
    ws[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1);
    ws[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2);
    ws[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3);
    ws[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 32U);
    ws[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 32U);
    ws[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 32U);
    ws[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 32U);
    ws[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 64U);
    ws[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 64U);
    ws[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 64U);
    ws[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 64U);
    ws[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 96U);
    ws[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 96U);
    ws[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 96U);
    ws[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 96U);
    ws[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 128U);
    ws[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 128U);
    ws[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 128U);
    ws[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 128U);
    ws[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 160U);
    ws[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 160U);
    ws[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 160U);
    ws[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 160U);
    ws[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 192U);
    ws[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 192U);
    ws[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 192U);
    ws[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 192U);
    ws[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 224U);
    ws[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 224U);
    ws[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 224U);
    ws[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 224U);
    Lib_IntVector_Intrinsics_vec256 v00 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v10 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v20 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v30 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256
    v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__;
    Lib_IntVector_Intrinsics_vec256 v01 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v11 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v21 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v31 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256
    v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__0;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__0;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__0;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__0;
    Lib_IntVector_Intrinsics_vec256 v02 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v12 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v22 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v32 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256
    v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__1;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__1;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__1;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__1;
    Lib_IntVector_Intrinsics_vec256 v03 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v13 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v23 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v33 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256
    v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__2;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__2;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__2;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__2;
    Lib_IntVector_Intrinsics_vec256 v04 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v14 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v24 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v34 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256
    v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__3;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__3;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__3;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__3;
    Lib_IntVector_Intrinsics_vec256 v05 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v15 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v25 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v35 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256
    v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__4;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__4;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__4;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__4;
    Lib_IntVector_Intrinsics_vec256 v06 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v16 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v26 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v36 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256
    v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__5;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__5;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__5;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__5;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256
    v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__6;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__6;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__6;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__6;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 25U; i++)
    {
      s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws[i]);
    }
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____0 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____1 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____2 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____0,
            Lib_IntVector_Intrinsics_vec256_xor(uu____1,
              Lib_IntVector_Intrinsics_vec256_xor(uu____2,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____3 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____4 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____3,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____4,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____4, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____5 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____5,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____5, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____6 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____7 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v07 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____6,
            Lib_IntVector_Intrinsics_vec256_and(uu____7, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____8 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____9 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v17 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____8,
            Lib_IntVector_Intrinsics_vec256_and(uu____9, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____10 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____11 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v27 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____10,
            Lib_IntVector_Intrinsics_vec256_and(uu____11, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____12 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____13 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v37 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____12,
            Lib_IntVector_Intrinsics_vec256_and(uu____13, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____14 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____15 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____14,
            Lib_IntVector_Intrinsics_vec256_and(uu____15, s[1U + 5U * i]));
        s[0U + 5U * i] = v07;
        s[1U + 5U * i] = v17;
        s[2U + 5U * i] = v27;
        s[3U + 5U * i] = v37;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____16 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____16,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t rem = inputByteLen % rateInBytes;
  uint8_t b00[256U] = { 0U };
  uint8_t b10[256U] = { 0U };
  uint8_t b20[256U] = { 0U };
  uint8_t b30[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
  uint32_t rem1 = inputByteLen % rateInBytes;
  uint8_t *b32 = ib.snd.snd.snd;
  uint8_t *b22 = ib.snd.snd.fst;
  uint8_t *b12 = ib.snd.fst;
  uint8_t *b02 = ib.fst;
  uint8_t *bl3 = b_.snd.snd.snd;
  uint8_t *bl2 = b_.snd.snd.fst;
  uint8_t *bl1 = b_.snd.fst;
  uint8_t *bl0 = b_.fst;
  memcpy(bl0, b02 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl1, b12 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl2, b22 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl3, b32 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  uint8_t *b33 = b_.snd.snd.snd;
  uint8_t *b23 = b_.snd.snd.fst;
  uint8_t *b13 = b_.snd.fst;
  uint8_t *b03 = b_.fst;
  b03[rem] = 0x1FU;
  b13[rem] = 0x1FU;
  b23[rem] = 0x1FU;
  b33[rem] = 0x1FU;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws32[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b34 = b_.snd.snd.snd;
  uint8_t *b24 = b_.snd.snd.fst;
  uint8_t *b14 = b_.snd.fst;
  uint8_t *b04 = b_.fst;
  ws32[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04);
  ws32[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14);
  ws32[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24);
  ws32[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34);
  ws32[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 32U);
  ws32[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 32U);
  ws32[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 32U);
  ws32[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 32U);
  ws32[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 64U);
  ws32[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 64U);
  ws32[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 64U);
  ws32[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 64U);
  ws32[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 96U);
  ws32[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 96U);
  ws32[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 96U);
  ws32[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 96U);
  ws32[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 128U);
  ws32[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 128U);
  ws32[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 128U);
  ws32[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 128U);
  ws32[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 160U);
  ws32[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 160U);
  ws32[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 160U);
  ws32[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 160U);
  ws32[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 192U);
  ws32[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 192U);
  ws32[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 192U);
  ws32[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 192U);
  ws32[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 224U);
  ws32[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 224U);
  ws32[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 224U);
  ws32[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 224U);
  Lib_IntVector_Intrinsics_vec256 v00 = ws32[0U];
  Lib_IntVector_Intrinsics_vec256 v10 = ws32[1U];
  Lib_IntVector_Intrinsics_vec256 v20 = ws32[2U];
  Lib_IntVector_Intrinsics_vec256 v30 = ws32[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256
  v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256 ws00 = v0__;
  Lib_IntVector_Intrinsics_vec256 ws110 = v2__;
  Lib_IntVector_Intrinsics_vec256 ws210 = v1__;
  Lib_IntVector_Intrinsics_vec256 ws33 = v3__;
  Lib_IntVector_Intrinsics_vec256 v01 = ws32[4U];
  Lib_IntVector_Intrinsics_vec256 v11 = ws32[5U];
  Lib_IntVector_Intrinsics_vec256 v21 = ws32[6U];
  Lib_IntVector_Intrinsics_vec256 v31 = ws32[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256
  v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256 ws40 = v0__0;
  Lib_IntVector_Intrinsics_vec256 ws50 = v2__0;
  Lib_IntVector_Intrinsics_vec256 ws60 = v1__0;
  Lib_IntVector_Intrinsics_vec256 ws70 = v3__0;
  Lib_IntVector_Intrinsics_vec256 v02 = ws32[8U];
  Lib_IntVector_Intrinsics_vec256 v12 = ws32[9U];
  Lib_IntVector_Intrinsics_vec256 v22 = ws32[10U];
  Lib_IntVector_Intrinsics_vec256 v32 = ws32[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256
  v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256 ws80 = v0__1;
  Lib_IntVector_Intrinsics_vec256 ws90 = v2__1;
  Lib_IntVector_Intrinsics_vec256 ws100 = v1__1;
  Lib_IntVector_Intrinsics_vec256 ws111 = v3__1;
  Lib_IntVector_Intrinsics_vec256 v03 = ws32[12U];
  Lib_IntVector_Intrinsics_vec256 v13 = ws32[13U];
  Lib_IntVector_Intrinsics_vec256 v23 = ws32[14U];
  Lib_IntVector_Intrinsics_vec256 v33 = ws32[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256
  v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256 ws120 = v0__2;
  Lib_IntVector_Intrinsics_vec256 ws130 = v2__2;
  Lib_IntVector_Intrinsics_vec256 ws140 = v1__2;
  Lib_IntVector_Intrinsics_vec256 ws150 = v3__2;
  Lib_IntVector_Intrinsics_vec256 v04 = ws32[16U];
  Lib_IntVector_Intrinsics_vec256 v14 = ws32[17U];
  Lib_IntVector_Intrinsics_vec256 v24 = ws32[18U];
  Lib_IntVector_Intrinsics_vec256 v34 = ws32[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256
  v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256 ws160 = v0__3;
  Lib_IntVector_Intrinsics_vec256 ws170 = v2__3;
  Lib_IntVector_Intrinsics_vec256 ws180 = v1__3;
  Lib_IntVector_Intrinsics_vec256 ws190 = v3__3;
  Lib_IntVector_Intrinsics_vec256 v05 = ws32[20U];
  Lib_IntVector_Intrinsics_vec256 v15 = ws32[21U];
  Lib_IntVector_Intrinsics_vec256 v25 = ws32[22U];
  Lib_IntVector_Intrinsics_vec256 v35 = ws32[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256
  v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256 ws200 = v0__4;
  Lib_IntVector_Intrinsics_vec256 ws211 = v2__4;
  Lib_IntVector_Intrinsics_vec256 ws220 = v1__4;
  Lib_IntVector_Intrinsics_vec256 ws230 = v3__4;
  Lib_IntVector_Intrinsics_vec256 v06 = ws32[24U];
  Lib_IntVector_Intrinsics_vec256 v16 = ws32[25U];
  Lib_IntVector_Intrinsics_vec256 v26 = ws32[26U];
  Lib_IntVector_Intrinsics_vec256 v36 = ws32[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256
  v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256 ws240 = v0__5;
  Lib_IntVector_Intrinsics_vec256 ws250 = v2__5;
  Lib_IntVector_Intrinsics_vec256 ws260 = v1__5;
  Lib_IntVector_Intrinsics_vec256 ws270 = v3__5;
  Lib_IntVector_Intrinsics_vec256 v07 = ws32[28U];
  Lib_IntVector_Intrinsics_vec256 v17 = ws32[29U];
  Lib_IntVector_Intrinsics_vec256 v27 = ws32[30U];
  Lib_IntVector_Intrinsics_vec256 v37 = ws32[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256
  v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256 ws280 = v0__6;
  Lib_IntVector_Intrinsics_vec256 ws290 = v2__6;
  Lib_IntVector_Intrinsics_vec256 ws300 = v1__6;
  Lib_IntVector_Intrinsics_vec256 ws310 = v3__6;
  ws32[0U] = ws00;
  ws32[1U] = ws110;
  ws32[2U] = ws210;
  ws32[3U] = ws33;
  ws32[4U] = ws40;
  ws32[5U] = ws50;
  ws32[6U] = ws60;
  ws32[7U] = ws70;
  ws32[8U] = ws80;
  ws32[9U] = ws90;
  ws32[10U] = ws100;
  ws32[11U] = ws111;
  ws32[12U] = ws120;
  ws32[13U] = ws130;
  ws32[14U] = ws140;
  ws32[15U] = ws150;
  ws32[16U] = ws160;
  ws32[17U] = ws170;
  ws32[18U] = ws180;
  ws32[19U] = ws190;
  ws32[20U] = ws200;
  ws32[21U] = ws211;
  ws32[22U] = ws220;
  ws32[23U] = ws230;
  ws32[24U] = ws240;
  ws32[25U] = ws250;
  ws32[26U] = ws260;
  ws32[27U] = ws270;
  ws32[28U] = ws280;
  ws32[29U] = ws290;
  ws32[30U] = ws300;
  ws32[31U] = ws310;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws32[i]);
  }
  uint8_t b05[256U] = { 0U };
  uint8_t b15[256U] = { 0U };
  uint8_t b25[256U] = { 0U };
  uint8_t b35[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b = { .fst = b05, .snd = { .fst = b15, .snd = { .fst = b25, .snd = b35 } } };
  uint8_t *b36 = b.snd.snd.snd;
  uint8_t *b26 = b.snd.snd.fst;
  uint8_t *b16 = b.snd.fst;
  uint8_t *b06 = b.fst;
  b06[rateInBytes - 1U] = 0x80U;
  b16[rateInBytes - 1U] = 0x80U;
  b26[rateInBytes - 1U] = 0x80U;
  b36[rateInBytes - 1U] = 0x80U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws34[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b37 = b.snd.snd.snd;
  uint8_t *b27 = b.snd.snd.fst;
  uint8_t *b17 = b.snd.fst;
  uint8_t *b07 = b.fst;
  ws34[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07);
  ws34[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17);
  ws34[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27);
  ws34[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37);
  ws34[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 32U);
  ws34[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 32U);
  ws34[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 32U);
  ws34[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 32U);
  ws34[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 64U);
  ws34[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 64U);
  ws34[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 64U);
  ws34[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 64U);
  ws34[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 96U);
  ws34[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 96U);
  ws34[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 96U);
  ws34[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 96U);
  ws34[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 128U);
  ws34[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 128U);
  ws34[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 128U);
  ws34[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 128U);
  ws34[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 160U);
  ws34[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 160U);
  ws34[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 160U);
  ws34[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 160U);
  ws34[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 192U);
  ws34[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 192U);
  ws34[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 192U);
  ws34[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 192U);
  ws34[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 224U);
  ws34[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 224U);
  ws34[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 224U);
  ws34[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 224U);
  Lib_IntVector_Intrinsics_vec256 v08 = ws34[0U];
  Lib_IntVector_Intrinsics_vec256 v18 = ws34[1U];
  Lib_IntVector_Intrinsics_vec256 v28 = ws34[2U];
  Lib_IntVector_Intrinsics_vec256 v38 = ws34[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v1_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v2_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v3_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v0__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v1__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v2__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256
  v3__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256 ws01 = v0__7;
  Lib_IntVector_Intrinsics_vec256 ws112 = v2__7;
  Lib_IntVector_Intrinsics_vec256 ws212 = v1__7;
  Lib_IntVector_Intrinsics_vec256 ws35 = v3__7;
  Lib_IntVector_Intrinsics_vec256 v09 = ws34[4U];
  Lib_IntVector_Intrinsics_vec256 v19 = ws34[5U];
  Lib_IntVector_Intrinsics_vec256 v29 = ws34[6U];
  Lib_IntVector_Intrinsics_vec256 v39 = ws34[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v1_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v2_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v3_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v0__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v1__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v2__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256
  v3__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256 ws41 = v0__8;
  Lib_IntVector_Intrinsics_vec256 ws51 = v2__8;
  Lib_IntVector_Intrinsics_vec256 ws61 = v1__8;
  Lib_IntVector_Intrinsics_vec256 ws71 = v3__8;
  Lib_IntVector_Intrinsics_vec256 v010 = ws34[8U];
  Lib_IntVector_Intrinsics_vec256 v110 = ws34[9U];
  Lib_IntVector_Intrinsics_vec256 v210 = ws34[10U];
  Lib_IntVector_Intrinsics_vec256 v310 = ws34[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v1_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v2_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v3_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v0__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v1__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v2__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256
  v3__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256 ws81 = v0__9;
  Lib_IntVector_Intrinsics_vec256 ws91 = v2__9;
  Lib_IntVector_Intrinsics_vec256 ws101 = v1__9;
  Lib_IntVector_Intrinsics_vec256 ws113 = v3__9;
  Lib_IntVector_Intrinsics_vec256 v011 = ws34[12U];
  Lib_IntVector_Intrinsics_vec256 v111 = ws34[13U];
  Lib_IntVector_Intrinsics_vec256 v211 = ws34[14U];
  Lib_IntVector_Intrinsics_vec256 v311 = ws34[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v1_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v2_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v3_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v0__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v1__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v2__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256
  v3__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256 ws121 = v0__10;
  Lib_IntVector_Intrinsics_vec256 ws131 = v2__10;
  Lib_IntVector_Intrinsics_vec256 ws141 = v1__10;
  Lib_IntVector_Intrinsics_vec256 ws151 = v3__10;
  Lib_IntVector_Intrinsics_vec256 v012 = ws34[16U];
  Lib_IntVector_Intrinsics_vec256 v112 = ws34[17U];
  Lib_IntVector_Intrinsics_vec256 v212 = ws34[18U];
  Lib_IntVector_Intrinsics_vec256 v312 = ws34[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v1_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v2_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v3_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v0__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v1__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v2__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256
  v3__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256 ws161 = v0__11;
  Lib_IntVector_Intrinsics_vec256 ws171 = v2__11;
  Lib_IntVector_Intrinsics_vec256 ws181 = v1__11;
  Lib_IntVector_Intrinsics_vec256 ws191 = v3__11;
  Lib_IntVector_Intrinsics_vec256 v013 = ws34[20U];
  Lib_IntVector_Intrinsics_vec256 v113 = ws34[21U];
  Lib_IntVector_Intrinsics_vec256 v213 = ws34[22U];
  Lib_IntVector_Intrinsics_vec256 v313 = ws34[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v1_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v2_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v3_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v0__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v1__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v2__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256
  v3__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256 ws201 = v0__12;
  Lib_IntVector_Intrinsics_vec256 ws213 = v2__12;
  Lib_IntVector_Intrinsics_vec256 ws221 = v1__12;
  Lib_IntVector_Intrinsics_vec256 ws231 = v3__12;
  Lib_IntVector_Intrinsics_vec256 v014 = ws34[24U];
  Lib_IntVector_Intrinsics_vec256 v114 = ws34[25U];
  Lib_IntVector_Intrinsics_vec256 v214 = ws34[26U];
  Lib_IntVector_Intrinsics_vec256 v314 = ws34[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v1_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v2_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v3_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v0__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v1__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v2__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256
  v3__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256 ws241 = v0__13;
  Lib_IntVector_Intrinsics_vec256 ws251 = v2__13;
  Lib_IntVector_Intrinsics_vec256 ws261 = v1__13;
  Lib_IntVector_Intrinsics_vec256 ws271 = v3__13;
  Lib_IntVector_Intrinsics_vec256 v015 = ws34[28U];
  Lib_IntVector_Intrinsics_vec256 v115 = ws34[29U];
  Lib_IntVector_Intrinsics_vec256 v215 = ws34[30U];
  Lib_IntVector_Intrinsics_vec256 v315 = ws34[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v1_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v2_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v3_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v0__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v1__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v2__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256
  v3__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256 ws281 = v0__14;
  Lib_IntVector_Intrinsics_vec256 ws291 = v2__14;
  Lib_IntVector_Intrinsics_vec256 ws301 = v1__14;
  Lib_IntVector_Intrinsics_vec256 ws311 = v3__14;
  ws34[0U] = ws01;
  ws34[1U] = ws112;
  ws34[2U] = ws212;
  ws34[3U] = ws35;
  ws34[4U] = ws41;
  ws34[5U] = ws51;
  ws34[6U] = ws61;
  ws34[7U] = ws71;
  ws34[8U] = ws81;
  ws34[9U] = ws91;
  ws34[10U] = ws101;
  ws34[11U] = ws113;
  ws34[12U] = ws121;
  ws34[13U] = ws131;
  ws34[14U] = ws141;
  ws34[15U] = ws151;
  ws34[16U] = ws161;
  ws34[17U] = ws171;
  ws34[18U] = ws181;
  ws34[19U] = ws191;
  ws34[20U] = ws201;
  ws34[21U] = ws213;
  ws34[22U] = ws221;
  ws34[23U] = ws231;
  ws34[24U] = ws241;
  ws34[25U] = ws251;
  ws34[26U] = ws261;
  ws34[27U] = ws271;
  ws34[28U] = ws281;
  ws34[29U] = ws291;
  ws34[30U] = ws301;
  ws34[31U] = ws311;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws34[i]);
  }
  for (uint32_t i0 = 0U; i0 < 24U; i0++)
  {
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____17 = s[i + 0U];
      Lib_IntVector_Intrinsics_vec256 uu____18 = s[i + 5U];
      Lib_IntVector_Intrinsics_vec256 uu____19 = s[i + 10U];
      _C[i] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____17,
          Lib_IntVector_Intrinsics_vec256_xor(uu____18,
            Lib_IntVector_Intrinsics_vec256_xor(uu____19,
              Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
    KRML_MAYBE_FOR5(i1,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____20 = _C[(i1 + 4U) % 5U];
      Lib_IntVector_Intrinsics_vec256 uu____21 = _C[(i1 + 1U) % 5U];
      Lib_IntVector_Intrinsics_vec256
      _D =
        Lib_IntVector_Intrinsics_vec256_xor(uu____20,
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____21,
              1U),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____21, 63U)));
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        s[i1 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i1 + 5U * i], _D);););
    Lib_IntVector_Intrinsics_vec256 x = s[1U];
    Lib_IntVector_Intrinsics_vec256 current = x;
    for (uint32_t i = 0U; i < 24U; i++)
    {
      uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
      uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
      Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
      Lib_IntVector_Intrinsics_vec256 uu____22 = current;
      s[_Y] =
        Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____22, r),
          Lib_IntVector_Intrinsics_vec256_shift_right64(uu____22, 64U - r));
      current = temp;
    }
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____23 = s[0U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____24 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v0 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____23,
          Lib_IntVector_Intrinsics_vec256_and(uu____24, s[2U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____25 = s[1U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____26 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v1 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____25,
          Lib_IntVector_Intrinsics_vec256_and(uu____26, s[3U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____27 = s[2U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____28 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v2 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____27,
          Lib_IntVector_Intrinsics_vec256_and(uu____28, s[4U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____29 = s[3U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____30 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v3 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____29,
          Lib_IntVector_Intrinsics_vec256_and(uu____30, s[0U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____31 = s[4U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____32 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v4 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____31,
          Lib_IntVector_Intrinsics_vec256_and(uu____32, s[1U + 5U * i]));
      s[0U + 5U * i] = v0;
      s[1U + 5U * i] = v1;
      s[2U + 5U * i] = v2;
      s[3U + 5U * i] = v3;
      s[4U + 5U * i] = v4;);
    uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i0];
    Lib_IntVector_Intrinsics_vec256 uu____33 = s[0U];
    s[0U] =
      Lib_IntVector_Intrinsics_vec256_xor(uu____33,
        Lib_IntVector_Intrinsics_vec256_load64(c));
  }
  for (uint32_t i0 = 0U; i0 < outputByteLen / rateInBytes; i0++)
  {
    uint8_t hbuf[1024U] = { 0U };
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
    Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256
    v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
    Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256
    v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
    Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256
    v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
    Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256
    v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
    Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256
    v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
    Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256
    v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
    Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256
    v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256
    v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 32U; i++)
    {
      Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
    }
    for (uint32_t i = 0U; i < rateInBytes / 32U; i++)
    {
      uint8_t *b31 = rb.snd.snd.snd;
      uint8_t *b21 = rb.snd.snd.fst;
      uint8_t *b11 = rb.snd.fst;
      uint8_t *b01 = rb.fst;
      memcpy(b01 + i0 * rateInBytes + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
      memcpy(b11 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
      memcpy(b21 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
      memcpy(b31 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
    }
    uint32_t rem0 = rateInBytes % 32U;
    uint32_t j = rateInBytes / 32U;
    uint8_t *b31 = rb.snd.snd.snd;
    uint8_t *b21 = rb.snd.snd.fst;
    uint8_t *b11 = rb.snd.fst;
    uint8_t *b01 = rb.fst;
    memcpy(b01 + i0 * rateInBytes + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
    memcpy(b11 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
    memcpy(b21 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
    memcpy(b31 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____34 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____35 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____36 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____34,
            Lib_IntVector_Intrinsics_vec256_xor(uu____35,
              Lib_IntVector_Intrinsics_vec256_xor(uu____36,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____37 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____38 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____37,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____38,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____38, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____39 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____39,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____39, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____40 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____41 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v023 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____40,
            Lib_IntVector_Intrinsics_vec256_and(uu____41, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____42 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____43 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v123 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____42,
            Lib_IntVector_Intrinsics_vec256_and(uu____43, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____44 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____45 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v223 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____44,
            Lib_IntVector_Intrinsics_vec256_and(uu____45, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____46 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____47 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v323 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____46,
            Lib_IntVector_Intrinsics_vec256_and(uu____47, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____48 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____49 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____48,
            Lib_IntVector_Intrinsics_vec256_and(uu____49, s[1U + 5U * i]));
        s[0U + 5U * i] = v023;
        s[1U + 5U * i] = v123;
        s[2U + 5U * i] = v223;
        s[3U + 5U * i] = v323;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____50 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____50,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t remOut = outputByteLen % rateInBytes;
  uint8_t hbuf[1024U] = { 0U };
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
  memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
  Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
  Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
  Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
  Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256
  v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
  Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
  Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
  Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
  Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
  Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
  Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
  Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256
  v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
  Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
  Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
  Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
  Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
  Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
  Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
  Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256
  v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
  Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
  Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
  Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
  Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
  Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
  Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
  Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256
  v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
  Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
  Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
  Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
  Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
  Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
  Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
  Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256
  v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
  Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
  Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
  Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
  Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
  Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
  Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
  Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256
  v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
  Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
  Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
  Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
  Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
  Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
  Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
  Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256
  v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
  Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
  Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
  Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
  Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
  Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
  Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
  Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256
  v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
  Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
  Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
  Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
  ws[0U] = ws0;
  ws[1U] = ws1;
  ws[2U] = ws2;
  ws[3U] = ws3;
  ws[4U] = ws4;
  ws[5U] = ws5;
  ws[6U] = ws6;
  ws[7U] = ws7;
  ws[8U] = ws8;
  ws[9U] = ws9;
  ws[10U] = ws10;
  ws[11U] = ws11;
  ws[12U] = ws12;
  ws[13U] = ws13;
  ws[14U] = ws14;
  ws[15U] = ws15;
  ws[16U] = ws16;
  ws[17U] = ws17;
  ws[18U] = ws18;
  ws[19U] = ws19;
  ws[20U] = ws20;
  ws[21U] = ws21;
  ws[22U] = ws22;
  ws[23U] = ws23;
  ws[24U] = ws24;
  ws[25U] = ws25;
  ws[26U] = ws26;
  ws[27U] = ws27;
  ws[28U] = ws28;
  ws[29U] = ws29;
  ws[30U] = ws30;
  ws[31U] = ws31;
  for (uint32_t i = 0U; i < 32U; i++)
  {
    Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
  }
  for (uint32_t i = 0U; i < remOut / 32U; i++)
  {
    uint8_t *b3 = rb.snd.snd.snd;
    uint8_t *b2 = rb.snd.snd.fst;
    uint8_t *b1 = rb.snd.fst;
    uint8_t *b0 = rb.fst;
    memcpy(b0 + outputByteLen - remOut + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
    memcpy(b1 + outputByteLen - remOut + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
    memcpy(b2 + outputByteLen - remOut + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
    memcpy(b3 + outputByteLen - remOut + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
  }
  uint32_t rem0 = remOut % 32U;
  uint32_t j = remOut / 32U;
  uint8_t *b3 = rb.snd.snd.snd;
  uint8_t *b2 = rb.snd.snd.fst;
  uint8_t *b1 = rb.snd.fst;
  uint8_t *b0 = rb.fst;
  memcpy(b0 + outputByteLen - remOut + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
  memcpy(b1 + outputByteLen - remOut + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
  memcpy(b2 + outputByteLen - remOut + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
  memcpy(b3 + outputByteLen - remOut + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
}

void
Hacl_Hash_SHA3_Simd256_shake256(
  uint32_t inputByteLen,
  uint8_t *input0,
  uint8_t *input1,
  uint8_t *input2,
  uint8_t *input3,
  uint32_t outputByteLen,
  uint8_t *output0,
  uint8_t *output1,
  uint8_t *output2,
  uint8_t *output3
)
{
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  ib = { .fst = input0, .snd = { .fst = input1, .snd = { .fst = input2, .snd = input3 } } };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  rb = { .fst = output0, .snd = { .fst = output1, .snd = { .fst = output2, .snd = output3 } } };
  uint32_t rateInBytes = 136U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 s[25U] KRML_POST_ALIGN(32) = { 0U };
  for (uint32_t i0 = 0U; i0 < inputByteLen / rateInBytes; i0++)
  {
    uint8_t b00[256U] = { 0U };
    uint8_t b10[256U] = { 0U };
    uint8_t b20[256U] = { 0U };
    uint8_t b30[256U] = { 0U };
    K____uint8_t___uint8_t____K____uint8_t___uint8_t_
    b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
    uint8_t *b31 = ib.snd.snd.snd;
    uint8_t *b21 = ib.snd.snd.fst;
    uint8_t *b11 = ib.snd.fst;
    uint8_t *b01 = ib.fst;
    uint8_t *bl3 = b_.snd.snd.snd;
    uint8_t *bl2 = b_.snd.snd.fst;
    uint8_t *bl1 = b_.snd.fst;
    uint8_t *bl0 = b_.fst;
    memcpy(bl0, b01 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl1, b11 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl2, b21 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl3, b31 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    uint8_t *b3 = b_.snd.snd.snd;
    uint8_t *b2 = b_.snd.snd.fst;
    uint8_t *b1 = b_.snd.fst;
    uint8_t *b0 = b_.fst;
    ws[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0);
    ws[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1);
    ws[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2);
    ws[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3);
    ws[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 32U);
    ws[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 32U);
    ws[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 32U);
    ws[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 32U);
    ws[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 64U);
    ws[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 64U);
    ws[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 64U);
    ws[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 64U);
    ws[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 96U);
    ws[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 96U);
    ws[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 96U);
    ws[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 96U);
    ws[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 128U);
    ws[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 128U);
    ws[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 128U);
    ws[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 128U);
    ws[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 160U);
    ws[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 160U);
    ws[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 160U);
    ws[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 160U);
    ws[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 192U);
    ws[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 192U);
    ws[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 192U);
    ws[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 192U);
    ws[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 224U);
    ws[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 224U);
    ws[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 224U);
    ws[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 224U);
    Lib_IntVector_Intrinsics_vec256 v00 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v10 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v20 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v30 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256
    v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__;
    Lib_IntVector_Intrinsics_vec256 v01 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v11 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v21 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v31 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256
    v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__0;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__0;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__0;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__0;
    Lib_IntVector_Intrinsics_vec256 v02 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v12 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v22 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v32 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256
    v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__1;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__1;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__1;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__1;
    Lib_IntVector_Intrinsics_vec256 v03 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v13 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v23 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v33 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256
    v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__2;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__2;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__2;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__2;
    Lib_IntVector_Intrinsics_vec256 v04 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v14 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v24 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v34 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256
    v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__3;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__3;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__3;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__3;
    Lib_IntVector_Intrinsics_vec256 v05 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v15 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v25 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v35 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256
    v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__4;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__4;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__4;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__4;
    Lib_IntVector_Intrinsics_vec256 v06 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v16 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v26 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v36 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256
    v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__5;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__5;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__5;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__5;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256
    v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__6;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__6;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__6;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__6;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 25U; i++)
    {
      s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws[i]);
    }
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____0 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____1 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____2 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____0,
            Lib_IntVector_Intrinsics_vec256_xor(uu____1,
              Lib_IntVector_Intrinsics_vec256_xor(uu____2,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____3 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____4 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____3,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____4,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____4, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____5 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____5,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____5, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____6 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____7 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v07 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____6,
            Lib_IntVector_Intrinsics_vec256_and(uu____7, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____8 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____9 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v17 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____8,
            Lib_IntVector_Intrinsics_vec256_and(uu____9, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____10 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____11 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v27 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____10,
            Lib_IntVector_Intrinsics_vec256_and(uu____11, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____12 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____13 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v37 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____12,
            Lib_IntVector_Intrinsics_vec256_and(uu____13, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____14 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____15 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____14,
            Lib_IntVector_Intrinsics_vec256_and(uu____15, s[1U + 5U * i]));
        s[0U + 5U * i] = v07;
        s[1U + 5U * i] = v17;
        s[2U + 5U * i] = v27;
        s[3U + 5U * i] = v37;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____16 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____16,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t rem = inputByteLen % rateInBytes;
  uint8_t b00[256U] = { 0U };
  uint8_t b10[256U] = { 0U };
  uint8_t b20[256U] = { 0U };
  uint8_t b30[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
  uint32_t rem1 = inputByteLen % rateInBytes;
  uint8_t *b32 = ib.snd.snd.snd;
  uint8_t *b22 = ib.snd.snd.fst;
  uint8_t *b12 = ib.snd.fst;
  uint8_t *b02 = ib.fst;
  uint8_t *bl3 = b_.snd.snd.snd;
  uint8_t *bl2 = b_.snd.snd.fst;
  uint8_t *bl1 = b_.snd.fst;
  uint8_t *bl0 = b_.fst;
  memcpy(bl0, b02 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl1, b12 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl2, b22 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl3, b32 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  uint8_t *b33 = b_.snd.snd.snd;
  uint8_t *b23 = b_.snd.snd.fst;
  uint8_t *b13 = b_.snd.fst;
  uint8_t *b03 = b_.fst;
  b03[rem] = 0x1FU;
  b13[rem] = 0x1FU;
  b23[rem] = 0x1FU;
  b33[rem] = 0x1FU;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws32[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b34 = b_.snd.snd.snd;
  uint8_t *b24 = b_.snd.snd.fst;
  uint8_t *b14 = b_.snd.fst;
  uint8_t *b04 = b_.fst;
  ws32[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04);
  ws32[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14);
  ws32[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24);
  ws32[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34);
  ws32[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 32U);
  ws32[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 32U);
  ws32[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 32U);
  ws32[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 32U);
  ws32[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 64U);
  ws32[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 64U);
  ws32[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 64U);
  ws32[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 64U);
  ws32[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 96U);
  ws32[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 96U);
  ws32[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 96U);
  ws32[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 96U);
  ws32[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 128U);
  ws32[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 128U);
  ws32[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 128U);
  ws32[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 128U);
  ws32[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 160U);
  ws32[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 160U);
  ws32[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 160U);
  ws32[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 160U);
  ws32[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 192U);
  ws32[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 192U);
  ws32[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 192U);
  ws32[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 192U);
  ws32[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 224U);
  ws32[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 224U);
  ws32[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 224U);
  ws32[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 224U);
  Lib_IntVector_Intrinsics_vec256 v00 = ws32[0U];
  Lib_IntVector_Intrinsics_vec256 v10 = ws32[1U];
  Lib_IntVector_Intrinsics_vec256 v20 = ws32[2U];
  Lib_IntVector_Intrinsics_vec256 v30 = ws32[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256
  v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256 ws00 = v0__;
  Lib_IntVector_Intrinsics_vec256 ws110 = v2__;
  Lib_IntVector_Intrinsics_vec256 ws210 = v1__;
  Lib_IntVector_Intrinsics_vec256 ws33 = v3__;
  Lib_IntVector_Intrinsics_vec256 v01 = ws32[4U];
  Lib_IntVector_Intrinsics_vec256 v11 = ws32[5U];
  Lib_IntVector_Intrinsics_vec256 v21 = ws32[6U];
  Lib_IntVector_Intrinsics_vec256 v31 = ws32[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256
  v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256 ws40 = v0__0;
  Lib_IntVector_Intrinsics_vec256 ws50 = v2__0;
  Lib_IntVector_Intrinsics_vec256 ws60 = v1__0;
  Lib_IntVector_Intrinsics_vec256 ws70 = v3__0;
  Lib_IntVector_Intrinsics_vec256 v02 = ws32[8U];
  Lib_IntVector_Intrinsics_vec256 v12 = ws32[9U];
  Lib_IntVector_Intrinsics_vec256 v22 = ws32[10U];
  Lib_IntVector_Intrinsics_vec256 v32 = ws32[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256
  v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256 ws80 = v0__1;
  Lib_IntVector_Intrinsics_vec256 ws90 = v2__1;
  Lib_IntVector_Intrinsics_vec256 ws100 = v1__1;
  Lib_IntVector_Intrinsics_vec256 ws111 = v3__1;
  Lib_IntVector_Intrinsics_vec256 v03 = ws32[12U];
  Lib_IntVector_Intrinsics_vec256 v13 = ws32[13U];
  Lib_IntVector_Intrinsics_vec256 v23 = ws32[14U];
  Lib_IntVector_Intrinsics_vec256 v33 = ws32[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256
  v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256 ws120 = v0__2;
  Lib_IntVector_Intrinsics_vec256 ws130 = v2__2;
  Lib_IntVector_Intrinsics_vec256 ws140 = v1__2;
  Lib_IntVector_Intrinsics_vec256 ws150 = v3__2;
  Lib_IntVector_Intrinsics_vec256 v04 = ws32[16U];
  Lib_IntVector_Intrinsics_vec256 v14 = ws32[17U];
  Lib_IntVector_Intrinsics_vec256 v24 = ws32[18U];
  Lib_IntVector_Intrinsics_vec256 v34 = ws32[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256
  v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256 ws160 = v0__3;
  Lib_IntVector_Intrinsics_vec256 ws170 = v2__3;
  Lib_IntVector_Intrinsics_vec256 ws180 = v1__3;
  Lib_IntVector_Intrinsics_vec256 ws190 = v3__3;
  Lib_IntVector_Intrinsics_vec256 v05 = ws32[20U];
  Lib_IntVector_Intrinsics_vec256 v15 = ws32[21U];
  Lib_IntVector_Intrinsics_vec256 v25 = ws32[22U];
  Lib_IntVector_Intrinsics_vec256 v35 = ws32[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256
  v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256 ws200 = v0__4;
  Lib_IntVector_Intrinsics_vec256 ws211 = v2__4;
  Lib_IntVector_Intrinsics_vec256 ws220 = v1__4;
  Lib_IntVector_Intrinsics_vec256 ws230 = v3__4;
  Lib_IntVector_Intrinsics_vec256 v06 = ws32[24U];
  Lib_IntVector_Intrinsics_vec256 v16 = ws32[25U];
  Lib_IntVector_Intrinsics_vec256 v26 = ws32[26U];
  Lib_IntVector_Intrinsics_vec256 v36 = ws32[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256
  v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256 ws240 = v0__5;
  Lib_IntVector_Intrinsics_vec256 ws250 = v2__5;
  Lib_IntVector_Intrinsics_vec256 ws260 = v1__5;
  Lib_IntVector_Intrinsics_vec256 ws270 = v3__5;
  Lib_IntVector_Intrinsics_vec256 v07 = ws32[28U];
  Lib_IntVector_Intrinsics_vec256 v17 = ws32[29U];
  Lib_IntVector_Intrinsics_vec256 v27 = ws32[30U];
  Lib_IntVector_Intrinsics_vec256 v37 = ws32[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256
  v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256 ws280 = v0__6;
  Lib_IntVector_Intrinsics_vec256 ws290 = v2__6;
  Lib_IntVector_Intrinsics_vec256 ws300 = v1__6;
  Lib_IntVector_Intrinsics_vec256 ws310 = v3__6;
  ws32[0U] = ws00;
  ws32[1U] = ws110;
  ws32[2U] = ws210;
  ws32[3U] = ws33;
  ws32[4U] = ws40;
  ws32[5U] = ws50;
  ws32[6U] = ws60;
  ws32[7U] = ws70;
  ws32[8U] = ws80;
  ws32[9U] = ws90;
  ws32[10U] = ws100;
  ws32[11U] = ws111;
  ws32[12U] = ws120;
  ws32[13U] = ws130;
  ws32[14U] = ws140;
  ws32[15U] = ws150;
  ws32[16U] = ws160;
  ws32[17U] = ws170;
  ws32[18U] = ws180;
  ws32[19U] = ws190;
  ws32[20U] = ws200;
  ws32[21U] = ws211;
  ws32[22U] = ws220;
  ws32[23U] = ws230;
  ws32[24U] = ws240;
  ws32[25U] = ws250;
  ws32[26U] = ws260;
  ws32[27U] = ws270;
  ws32[28U] = ws280;
  ws32[29U] = ws290;
  ws32[30U] = ws300;
  ws32[31U] = ws310;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws32[i]);
  }
  uint8_t b05[256U] = { 0U };
  uint8_t b15[256U] = { 0U };
  uint8_t b25[256U] = { 0U };
  uint8_t b35[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b = { .fst = b05, .snd = { .fst = b15, .snd = { .fst = b25, .snd = b35 } } };
  uint8_t *b36 = b.snd.snd.snd;
  uint8_t *b26 = b.snd.snd.fst;
  uint8_t *b16 = b.snd.fst;
  uint8_t *b06 = b.fst;
  b06[rateInBytes - 1U] = 0x80U;
  b16[rateInBytes - 1U] = 0x80U;
  b26[rateInBytes - 1U] = 0x80U;
  b36[rateInBytes - 1U] = 0x80U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws34[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b37 = b.snd.snd.snd;
  uint8_t *b27 = b.snd.snd.fst;
  uint8_t *b17 = b.snd.fst;
  uint8_t *b07 = b.fst;
  ws34[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07);
  ws34[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17);
  ws34[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27);
  ws34[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37);
  ws34[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 32U);
  ws34[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 32U);
  ws34[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 32U);
  ws34[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 32U);
  ws34[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 64U);
  ws34[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 64U);
  ws34[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 64U);
  ws34[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 64U);
  ws34[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 96U);
  ws34[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 96U);
  ws34[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 96U);
  ws34[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 96U);
  ws34[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 128U);
  ws34[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 128U);
  ws34[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 128U);
  ws34[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 128U);
  ws34[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 160U);
  ws34[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 160U);
  ws34[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 160U);
  ws34[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 160U);
  ws34[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 192U);
  ws34[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 192U);
  ws34[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 192U);
  ws34[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 192U);
  ws34[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 224U);
  ws34[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 224U);
  ws34[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 224U);
  ws34[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 224U);
  Lib_IntVector_Intrinsics_vec256 v08 = ws34[0U];
  Lib_IntVector_Intrinsics_vec256 v18 = ws34[1U];
  Lib_IntVector_Intrinsics_vec256 v28 = ws34[2U];
  Lib_IntVector_Intrinsics_vec256 v38 = ws34[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v1_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v2_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v3_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v0__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v1__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v2__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256
  v3__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256 ws01 = v0__7;
  Lib_IntVector_Intrinsics_vec256 ws112 = v2__7;
  Lib_IntVector_Intrinsics_vec256 ws212 = v1__7;
  Lib_IntVector_Intrinsics_vec256 ws35 = v3__7;
  Lib_IntVector_Intrinsics_vec256 v09 = ws34[4U];
  Lib_IntVector_Intrinsics_vec256 v19 = ws34[5U];
  Lib_IntVector_Intrinsics_vec256 v29 = ws34[6U];
  Lib_IntVector_Intrinsics_vec256 v39 = ws34[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v1_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v2_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v3_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v0__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v1__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v2__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256
  v3__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256 ws41 = v0__8;
  Lib_IntVector_Intrinsics_vec256 ws51 = v2__8;
  Lib_IntVector_Intrinsics_vec256 ws61 = v1__8;
  Lib_IntVector_Intrinsics_vec256 ws71 = v3__8;
  Lib_IntVector_Intrinsics_vec256 v010 = ws34[8U];
  Lib_IntVector_Intrinsics_vec256 v110 = ws34[9U];
  Lib_IntVector_Intrinsics_vec256 v210 = ws34[10U];
  Lib_IntVector_Intrinsics_vec256 v310 = ws34[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v1_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v2_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v3_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v0__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v1__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v2__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256
  v3__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256 ws81 = v0__9;
  Lib_IntVector_Intrinsics_vec256 ws91 = v2__9;
  Lib_IntVector_Intrinsics_vec256 ws101 = v1__9;
  Lib_IntVector_Intrinsics_vec256 ws113 = v3__9;
  Lib_IntVector_Intrinsics_vec256 v011 = ws34[12U];
  Lib_IntVector_Intrinsics_vec256 v111 = ws34[13U];
  Lib_IntVector_Intrinsics_vec256 v211 = ws34[14U];
  Lib_IntVector_Intrinsics_vec256 v311 = ws34[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v1_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v2_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v3_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v0__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v1__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v2__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256
  v3__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256 ws121 = v0__10;
  Lib_IntVector_Intrinsics_vec256 ws131 = v2__10;
  Lib_IntVector_Intrinsics_vec256 ws141 = v1__10;
  Lib_IntVector_Intrinsics_vec256 ws151 = v3__10;
  Lib_IntVector_Intrinsics_vec256 v012 = ws34[16U];
  Lib_IntVector_Intrinsics_vec256 v112 = ws34[17U];
  Lib_IntVector_Intrinsics_vec256 v212 = ws34[18U];
  Lib_IntVector_Intrinsics_vec256 v312 = ws34[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v1_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v2_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v3_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v0__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v1__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v2__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256
  v3__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256 ws161 = v0__11;
  Lib_IntVector_Intrinsics_vec256 ws171 = v2__11;
  Lib_IntVector_Intrinsics_vec256 ws181 = v1__11;
  Lib_IntVector_Intrinsics_vec256 ws191 = v3__11;
  Lib_IntVector_Intrinsics_vec256 v013 = ws34[20U];
  Lib_IntVector_Intrinsics_vec256 v113 = ws34[21U];
  Lib_IntVector_Intrinsics_vec256 v213 = ws34[22U];
  Lib_IntVector_Intrinsics_vec256 v313 = ws34[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v1_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v2_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v3_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v0__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v1__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v2__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256
  v3__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256 ws201 = v0__12;
  Lib_IntVector_Intrinsics_vec256 ws213 = v2__12;
  Lib_IntVector_Intrinsics_vec256 ws221 = v1__12;
  Lib_IntVector_Intrinsics_vec256 ws231 = v3__12;
  Lib_IntVector_Intrinsics_vec256 v014 = ws34[24U];
  Lib_IntVector_Intrinsics_vec256 v114 = ws34[25U];
  Lib_IntVector_Intrinsics_vec256 v214 = ws34[26U];
  Lib_IntVector_Intrinsics_vec256 v314 = ws34[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v1_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v2_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v3_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v0__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v1__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v2__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256
  v3__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256 ws241 = v0__13;
  Lib_IntVector_Intrinsics_vec256 ws251 = v2__13;
  Lib_IntVector_Intrinsics_vec256 ws261 = v1__13;
  Lib_IntVector_Intrinsics_vec256 ws271 = v3__13;
  Lib_IntVector_Intrinsics_vec256 v015 = ws34[28U];
  Lib_IntVector_Intrinsics_vec256 v115 = ws34[29U];
  Lib_IntVector_Intrinsics_vec256 v215 = ws34[30U];
  Lib_IntVector_Intrinsics_vec256 v315 = ws34[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v1_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v2_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v3_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v0__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v1__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v2__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256
  v3__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256 ws281 = v0__14;
  Lib_IntVector_Intrinsics_vec256 ws291 = v2__14;
  Lib_IntVector_Intrinsics_vec256 ws301 = v1__14;
  Lib_IntVector_Intrinsics_vec256 ws311 = v3__14;
  ws34[0U] = ws01;
  ws34[1U] = ws112;
  ws34[2U] = ws212;
  ws34[3U] = ws35;
  ws34[4U] = ws41;
  ws34[5U] = ws51;
  ws34[6U] = ws61;
  ws34[7U] = ws71;
  ws34[8U] = ws81;
  ws34[9U] = ws91;
  ws34[10U] = ws101;
  ws34[11U] = ws113;
  ws34[12U] = ws121;
  ws34[13U] = ws131;
  ws34[14U] = ws141;
  ws34[15U] = ws151;
  ws34[16U] = ws161;
  ws34[17U] = ws171;
  ws34[18U] = ws181;
  ws34[19U] = ws191;
  ws34[20U] = ws201;
  ws34[21U] = ws213;
  ws34[22U] = ws221;
  ws34[23U] = ws231;
  ws34[24U] = ws241;
  ws34[25U] = ws251;
  ws34[26U] = ws261;
  ws34[27U] = ws271;
  ws34[28U] = ws281;
  ws34[29U] = ws291;
  ws34[30U] = ws301;
  ws34[31U] = ws311;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws34[i]);
  }
  for (uint32_t i0 = 0U; i0 < 24U; i0++)
  {
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____17 = s[i + 0U];
      Lib_IntVector_Intrinsics_vec256 uu____18 = s[i + 5U];
      Lib_IntVector_Intrinsics_vec256 uu____19 = s[i + 10U];
      _C[i] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____17,
          Lib_IntVector_Intrinsics_vec256_xor(uu____18,
            Lib_IntVector_Intrinsics_vec256_xor(uu____19,
              Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
    KRML_MAYBE_FOR5(i1,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____20 = _C[(i1 + 4U) % 5U];
      Lib_IntVector_Intrinsics_vec256 uu____21 = _C[(i1 + 1U) % 5U];
      Lib_IntVector_Intrinsics_vec256
      _D =
        Lib_IntVector_Intrinsics_vec256_xor(uu____20,
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____21,
              1U),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____21, 63U)));
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        s[i1 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i1 + 5U * i], _D);););
    Lib_IntVector_Intrinsics_vec256 x = s[1U];
    Lib_IntVector_Intrinsics_vec256 current = x;
    for (uint32_t i = 0U; i < 24U; i++)
    {
      uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
      uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
      Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
      Lib_IntVector_Intrinsics_vec256 uu____22 = current;
      s[_Y] =
        Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____22, r),
          Lib_IntVector_Intrinsics_vec256_shift_right64(uu____22, 64U - r));
      current = temp;
    }
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____23 = s[0U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____24 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v0 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____23,
          Lib_IntVector_Intrinsics_vec256_and(uu____24, s[2U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____25 = s[1U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____26 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v1 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____25,
          Lib_IntVector_Intrinsics_vec256_and(uu____26, s[3U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____27 = s[2U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____28 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v2 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____27,
          Lib_IntVector_Intrinsics_vec256_and(uu____28, s[4U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____29 = s[3U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____30 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v3 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____29,
          Lib_IntVector_Intrinsics_vec256_and(uu____30, s[0U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____31 = s[4U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____32 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v4 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____31,
          Lib_IntVector_Intrinsics_vec256_and(uu____32, s[1U + 5U * i]));
      s[0U + 5U * i] = v0;
      s[1U + 5U * i] = v1;
      s[2U + 5U * i] = v2;
      s[3U + 5U * i] = v3;
      s[4U + 5U * i] = v4;);
    uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i0];
    Lib_IntVector_Intrinsics_vec256 uu____33 = s[0U];
    s[0U] =
      Lib_IntVector_Intrinsics_vec256_xor(uu____33,
        Lib_IntVector_Intrinsics_vec256_load64(c));
  }
  for (uint32_t i0 = 0U; i0 < outputByteLen / rateInBytes; i0++)
  {
    uint8_t hbuf[1024U] = { 0U };
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
    Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256
    v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
    Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256
    v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
    Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256
    v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
    Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256
    v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
    Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256
    v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
    Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256
    v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
    Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256
    v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256
    v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 32U; i++)
    {
      Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
    }
    for (uint32_t i = 0U; i < rateInBytes / 32U; i++)
    {
      uint8_t *b31 = rb.snd.snd.snd;
      uint8_t *b21 = rb.snd.snd.fst;
      uint8_t *b11 = rb.snd.fst;
      uint8_t *b01 = rb.fst;
      memcpy(b01 + i0 * rateInBytes + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
      memcpy(b11 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
      memcpy(b21 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
      memcpy(b31 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
    }
    uint32_t rem0 = rateInBytes % 32U;
    uint32_t j = rateInBytes / 32U;
    uint8_t *b31 = rb.snd.snd.snd;
    uint8_t *b21 = rb.snd.snd.fst;
    uint8_t *b11 = rb.snd.fst;
    uint8_t *b01 = rb.fst;
    memcpy(b01 + i0 * rateInBytes + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
    memcpy(b11 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
    memcpy(b21 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
    memcpy(b31 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____34 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____35 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____36 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____34,
            Lib_IntVector_Intrinsics_vec256_xor(uu____35,
              Lib_IntVector_Intrinsics_vec256_xor(uu____36,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____37 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____38 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____37,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____38,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____38, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____39 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____39,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____39, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____40 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____41 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v023 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____40,
            Lib_IntVector_Intrinsics_vec256_and(uu____41, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____42 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____43 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v123 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____42,
            Lib_IntVector_Intrinsics_vec256_and(uu____43, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____44 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____45 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v223 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____44,
            Lib_IntVector_Intrinsics_vec256_and(uu____45, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____46 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____47 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v323 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____46,
            Lib_IntVector_Intrinsics_vec256_and(uu____47, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____48 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____49 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____48,
            Lib_IntVector_Intrinsics_vec256_and(uu____49, s[1U + 5U * i]));
        s[0U + 5U * i] = v023;
        s[1U + 5U * i] = v123;
        s[2U + 5U * i] = v223;
        s[3U + 5U * i] = v323;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____50 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____50,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t remOut = outputByteLen % rateInBytes;
  uint8_t hbuf[1024U] = { 0U };
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
  memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
  Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
  Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
  Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
  Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256
  v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
  Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
  Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
  Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
  Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
  Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
  Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
  Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256
  v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
  Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
  Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
  Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
  Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
  Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
  Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
  Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256
  v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
  Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
  Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
  Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
  Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
  Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
  Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
  Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256
  v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
  Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
  Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
  Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
  Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
  Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
  Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
  Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256
  v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
  Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
  Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
  Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
  Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
  Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
  Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
  Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256
  v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
  Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
  Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
  Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
  Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
  Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
  Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
  Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256
  v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
  Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
  Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
  Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
  Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
  Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
  Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
  Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256
  v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
  Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
  Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
  Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
  ws[0U] = ws0;
  ws[1U] = ws1;
  ws[2U] = ws2;
  ws[3U] = ws3;
  ws[4U] = ws4;
  ws[5U] = ws5;
  ws[6U] = ws6;
  ws[7U] = ws7;
  ws[8U] = ws8;
  ws[9U] = ws9;
  ws[10U] = ws10;
  ws[11U] = ws11;
  ws[12U] = ws12;
  ws[13U] = ws13;
  ws[14U] = ws14;
  ws[15U] = ws15;
  ws[16U] = ws16;
  ws[17U] = ws17;
  ws[18U] = ws18;
  ws[19U] = ws19;
  ws[20U] = ws20;
  ws[21U] = ws21;
  ws[22U] = ws22;
  ws[23U] = ws23;
  ws[24U] = ws24;
  ws[25U] = ws25;
  ws[26U] = ws26;
  ws[27U] = ws27;
  ws[28U] = ws28;
  ws[29U] = ws29;
  ws[30U] = ws30;
  ws[31U] = ws31;
  for (uint32_t i = 0U; i < 32U; i++)
  {
    Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
  }
  for (uint32_t i = 0U; i < remOut / 32U; i++)
  {
    uint8_t *b3 = rb.snd.snd.snd;
    uint8_t *b2 = rb.snd.snd.fst;
    uint8_t *b1 = rb.snd.fst;
    uint8_t *b0 = rb.fst;
    memcpy(b0 + outputByteLen - remOut + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
    memcpy(b1 + outputByteLen - remOut + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
    memcpy(b2 + outputByteLen - remOut + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
    memcpy(b3 + outputByteLen - remOut + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
  }
  uint32_t rem0 = remOut % 32U;
  uint32_t j = remOut / 32U;
  uint8_t *b3 = rb.snd.snd.snd;
  uint8_t *b2 = rb.snd.snd.fst;
  uint8_t *b1 = rb.snd.fst;
  uint8_t *b0 = rb.fst;
  memcpy(b0 + outputByteLen - remOut + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
  memcpy(b1 + outputByteLen - remOut + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
  memcpy(b2 + outputByteLen - remOut + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
  memcpy(b3 + outputByteLen - remOut + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
}

void
Hacl_Hash_SHA3_Simd256_sha3_224(
  uint32_t inputByteLen,
  uint8_t *input0,
  uint8_t *input1,
  uint8_t *input2,
  uint8_t *input3,
  uint8_t *output0,
  uint8_t *output1,
  uint8_t *output2,
  uint8_t *output3
)
{
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  ib = { .fst = input0, .snd = { .fst = input1, .snd = { .fst = input2, .snd = input3 } } };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  rb = { .fst = output0, .snd = { .fst = output1, .snd = { .fst = output2, .snd = output3 } } };
  uint32_t rateInBytes = 144U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 s[25U] KRML_POST_ALIGN(32) = { 0U };
  for (uint32_t i0 = 0U; i0 < inputByteLen / rateInBytes; i0++)
  {
    uint8_t b00[256U] = { 0U };
    uint8_t b10[256U] = { 0U };
    uint8_t b20[256U] = { 0U };
    uint8_t b30[256U] = { 0U };
    K____uint8_t___uint8_t____K____uint8_t___uint8_t_
    b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
    uint8_t *b31 = ib.snd.snd.snd;
    uint8_t *b21 = ib.snd.snd.fst;
    uint8_t *b11 = ib.snd.fst;
    uint8_t *b01 = ib.fst;
    uint8_t *bl3 = b_.snd.snd.snd;
    uint8_t *bl2 = b_.snd.snd.fst;
    uint8_t *bl1 = b_.snd.fst;
    uint8_t *bl0 = b_.fst;
    memcpy(bl0, b01 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl1, b11 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl2, b21 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl3, b31 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    uint8_t *b3 = b_.snd.snd.snd;
    uint8_t *b2 = b_.snd.snd.fst;
    uint8_t *b1 = b_.snd.fst;
    uint8_t *b0 = b_.fst;
    ws[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0);
    ws[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1);
    ws[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2);
    ws[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3);
    ws[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 32U);
    ws[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 32U);
    ws[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 32U);
    ws[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 32U);
    ws[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 64U);
    ws[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 64U);
    ws[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 64U);
    ws[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 64U);
    ws[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 96U);
    ws[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 96U);
    ws[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 96U);
    ws[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 96U);
    ws[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 128U);
    ws[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 128U);
    ws[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 128U);
    ws[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 128U);
    ws[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 160U);
    ws[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 160U);
    ws[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 160U);
    ws[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 160U);
    ws[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 192U);
    ws[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 192U);
    ws[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 192U);
    ws[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 192U);
    ws[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 224U);
    ws[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 224U);
    ws[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 224U);
    ws[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 224U);
    Lib_IntVector_Intrinsics_vec256 v00 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v10 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v20 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v30 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256
    v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__;
    Lib_IntVector_Intrinsics_vec256 v01 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v11 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v21 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v31 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256
    v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__0;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__0;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__0;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__0;
    Lib_IntVector_Intrinsics_vec256 v02 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v12 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v22 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v32 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256
    v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__1;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__1;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__1;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__1;
    Lib_IntVector_Intrinsics_vec256 v03 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v13 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v23 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v33 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256
    v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__2;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__2;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__2;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__2;
    Lib_IntVector_Intrinsics_vec256 v04 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v14 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v24 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v34 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256
    v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__3;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__3;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__3;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__3;
    Lib_IntVector_Intrinsics_vec256 v05 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v15 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v25 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v35 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256
    v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__4;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__4;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__4;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__4;
    Lib_IntVector_Intrinsics_vec256 v06 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v16 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v26 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v36 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256
    v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__5;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__5;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__5;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__5;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256
    v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__6;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__6;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__6;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__6;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 25U; i++)
    {
      s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws[i]);
    }
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____0 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____1 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____2 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____0,
            Lib_IntVector_Intrinsics_vec256_xor(uu____1,
              Lib_IntVector_Intrinsics_vec256_xor(uu____2,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____3 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____4 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____3,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____4,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____4, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____5 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____5,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____5, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____6 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____7 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v07 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____6,
            Lib_IntVector_Intrinsics_vec256_and(uu____7, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____8 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____9 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v17 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____8,
            Lib_IntVector_Intrinsics_vec256_and(uu____9, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____10 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____11 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v27 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____10,
            Lib_IntVector_Intrinsics_vec256_and(uu____11, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____12 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____13 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v37 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____12,
            Lib_IntVector_Intrinsics_vec256_and(uu____13, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____14 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____15 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____14,
            Lib_IntVector_Intrinsics_vec256_and(uu____15, s[1U + 5U * i]));
        s[0U + 5U * i] = v07;
        s[1U + 5U * i] = v17;
        s[2U + 5U * i] = v27;
        s[3U + 5U * i] = v37;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____16 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____16,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t rem = inputByteLen % rateInBytes;
  uint8_t b00[256U] = { 0U };
  uint8_t b10[256U] = { 0U };
  uint8_t b20[256U] = { 0U };
  uint8_t b30[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
  uint32_t rem1 = inputByteLen % rateInBytes;
  uint8_t *b32 = ib.snd.snd.snd;
  uint8_t *b22 = ib.snd.snd.fst;
  uint8_t *b12 = ib.snd.fst;
  uint8_t *b02 = ib.fst;
  uint8_t *bl3 = b_.snd.snd.snd;
  uint8_t *bl2 = b_.snd.snd.fst;
  uint8_t *bl1 = b_.snd.fst;
  uint8_t *bl0 = b_.fst;
  memcpy(bl0, b02 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl1, b12 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl2, b22 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl3, b32 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  uint8_t *b33 = b_.snd.snd.snd;
  uint8_t *b23 = b_.snd.snd.fst;
  uint8_t *b13 = b_.snd.fst;
  uint8_t *b03 = b_.fst;
  b03[rem] = 0x06U;
  b13[rem] = 0x06U;
  b23[rem] = 0x06U;
  b33[rem] = 0x06U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws32[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b34 = b_.snd.snd.snd;
  uint8_t *b24 = b_.snd.snd.fst;
  uint8_t *b14 = b_.snd.fst;
  uint8_t *b04 = b_.fst;
  ws32[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04);
  ws32[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14);
  ws32[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24);
  ws32[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34);
  ws32[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 32U);
  ws32[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 32U);
  ws32[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 32U);
  ws32[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 32U);
  ws32[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 64U);
  ws32[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 64U);
  ws32[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 64U);
  ws32[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 64U);
  ws32[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 96U);
  ws32[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 96U);
  ws32[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 96U);
  ws32[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 96U);
  ws32[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 128U);
  ws32[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 128U);
  ws32[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 128U);
  ws32[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 128U);
  ws32[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 160U);
  ws32[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 160U);
  ws32[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 160U);
  ws32[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 160U);
  ws32[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 192U);
  ws32[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 192U);
  ws32[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 192U);
  ws32[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 192U);
  ws32[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 224U);
  ws32[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 224U);
  ws32[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 224U);
  ws32[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 224U);
  Lib_IntVector_Intrinsics_vec256 v00 = ws32[0U];
  Lib_IntVector_Intrinsics_vec256 v10 = ws32[1U];
  Lib_IntVector_Intrinsics_vec256 v20 = ws32[2U];
  Lib_IntVector_Intrinsics_vec256 v30 = ws32[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256
  v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256 ws00 = v0__;
  Lib_IntVector_Intrinsics_vec256 ws110 = v2__;
  Lib_IntVector_Intrinsics_vec256 ws210 = v1__;
  Lib_IntVector_Intrinsics_vec256 ws33 = v3__;
  Lib_IntVector_Intrinsics_vec256 v01 = ws32[4U];
  Lib_IntVector_Intrinsics_vec256 v11 = ws32[5U];
  Lib_IntVector_Intrinsics_vec256 v21 = ws32[6U];
  Lib_IntVector_Intrinsics_vec256 v31 = ws32[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256
  v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256 ws40 = v0__0;
  Lib_IntVector_Intrinsics_vec256 ws50 = v2__0;
  Lib_IntVector_Intrinsics_vec256 ws60 = v1__0;
  Lib_IntVector_Intrinsics_vec256 ws70 = v3__0;
  Lib_IntVector_Intrinsics_vec256 v02 = ws32[8U];
  Lib_IntVector_Intrinsics_vec256 v12 = ws32[9U];
  Lib_IntVector_Intrinsics_vec256 v22 = ws32[10U];
  Lib_IntVector_Intrinsics_vec256 v32 = ws32[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256
  v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256 ws80 = v0__1;
  Lib_IntVector_Intrinsics_vec256 ws90 = v2__1;
  Lib_IntVector_Intrinsics_vec256 ws100 = v1__1;
  Lib_IntVector_Intrinsics_vec256 ws111 = v3__1;
  Lib_IntVector_Intrinsics_vec256 v03 = ws32[12U];
  Lib_IntVector_Intrinsics_vec256 v13 = ws32[13U];
  Lib_IntVector_Intrinsics_vec256 v23 = ws32[14U];
  Lib_IntVector_Intrinsics_vec256 v33 = ws32[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256
  v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256 ws120 = v0__2;
  Lib_IntVector_Intrinsics_vec256 ws130 = v2__2;
  Lib_IntVector_Intrinsics_vec256 ws140 = v1__2;
  Lib_IntVector_Intrinsics_vec256 ws150 = v3__2;
  Lib_IntVector_Intrinsics_vec256 v04 = ws32[16U];
  Lib_IntVector_Intrinsics_vec256 v14 = ws32[17U];
  Lib_IntVector_Intrinsics_vec256 v24 = ws32[18U];
  Lib_IntVector_Intrinsics_vec256 v34 = ws32[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256
  v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256 ws160 = v0__3;
  Lib_IntVector_Intrinsics_vec256 ws170 = v2__3;
  Lib_IntVector_Intrinsics_vec256 ws180 = v1__3;
  Lib_IntVector_Intrinsics_vec256 ws190 = v3__3;
  Lib_IntVector_Intrinsics_vec256 v05 = ws32[20U];
  Lib_IntVector_Intrinsics_vec256 v15 = ws32[21U];
  Lib_IntVector_Intrinsics_vec256 v25 = ws32[22U];
  Lib_IntVector_Intrinsics_vec256 v35 = ws32[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256
  v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256 ws200 = v0__4;
  Lib_IntVector_Intrinsics_vec256 ws211 = v2__4;
  Lib_IntVector_Intrinsics_vec256 ws220 = v1__4;
  Lib_IntVector_Intrinsics_vec256 ws230 = v3__4;
  Lib_IntVector_Intrinsics_vec256 v06 = ws32[24U];
  Lib_IntVector_Intrinsics_vec256 v16 = ws32[25U];
  Lib_IntVector_Intrinsics_vec256 v26 = ws32[26U];
  Lib_IntVector_Intrinsics_vec256 v36 = ws32[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256
  v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256 ws240 = v0__5;
  Lib_IntVector_Intrinsics_vec256 ws250 = v2__5;
  Lib_IntVector_Intrinsics_vec256 ws260 = v1__5;
  Lib_IntVector_Intrinsics_vec256 ws270 = v3__5;
  Lib_IntVector_Intrinsics_vec256 v07 = ws32[28U];
  Lib_IntVector_Intrinsics_vec256 v17 = ws32[29U];
  Lib_IntVector_Intrinsics_vec256 v27 = ws32[30U];
  Lib_IntVector_Intrinsics_vec256 v37 = ws32[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256
  v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256 ws280 = v0__6;
  Lib_IntVector_Intrinsics_vec256 ws290 = v2__6;
  Lib_IntVector_Intrinsics_vec256 ws300 = v1__6;
  Lib_IntVector_Intrinsics_vec256 ws310 = v3__6;
  ws32[0U] = ws00;
  ws32[1U] = ws110;
  ws32[2U] = ws210;
  ws32[3U] = ws33;
  ws32[4U] = ws40;
  ws32[5U] = ws50;
  ws32[6U] = ws60;
  ws32[7U] = ws70;
  ws32[8U] = ws80;
  ws32[9U] = ws90;
  ws32[10U] = ws100;
  ws32[11U] = ws111;
  ws32[12U] = ws120;
  ws32[13U] = ws130;
  ws32[14U] = ws140;
  ws32[15U] = ws150;
  ws32[16U] = ws160;
  ws32[17U] = ws170;
  ws32[18U] = ws180;
  ws32[19U] = ws190;
  ws32[20U] = ws200;
  ws32[21U] = ws211;
  ws32[22U] = ws220;
  ws32[23U] = ws230;
  ws32[24U] = ws240;
  ws32[25U] = ws250;
  ws32[26U] = ws260;
  ws32[27U] = ws270;
  ws32[28U] = ws280;
  ws32[29U] = ws290;
  ws32[30U] = ws300;
  ws32[31U] = ws310;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws32[i]);
  }
  uint8_t b05[256U] = { 0U };
  uint8_t b15[256U] = { 0U };
  uint8_t b25[256U] = { 0U };
  uint8_t b35[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b = { .fst = b05, .snd = { .fst = b15, .snd = { .fst = b25, .snd = b35 } } };
  uint8_t *b36 = b.snd.snd.snd;
  uint8_t *b26 = b.snd.snd.fst;
  uint8_t *b16 = b.snd.fst;
  uint8_t *b06 = b.fst;
  b06[rateInBytes - 1U] = 0x80U;
  b16[rateInBytes - 1U] = 0x80U;
  b26[rateInBytes - 1U] = 0x80U;
  b36[rateInBytes - 1U] = 0x80U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws34[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b37 = b.snd.snd.snd;
  uint8_t *b27 = b.snd.snd.fst;
  uint8_t *b17 = b.snd.fst;
  uint8_t *b07 = b.fst;
  ws34[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07);
  ws34[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17);
  ws34[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27);
  ws34[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37);
  ws34[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 32U);
  ws34[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 32U);
  ws34[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 32U);
  ws34[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 32U);
  ws34[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 64U);
  ws34[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 64U);
  ws34[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 64U);
  ws34[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 64U);
  ws34[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 96U);
  ws34[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 96U);
  ws34[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 96U);
  ws34[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 96U);
  ws34[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 128U);
  ws34[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 128U);
  ws34[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 128U);
  ws34[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 128U);
  ws34[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 160U);
  ws34[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 160U);
  ws34[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 160U);
  ws34[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 160U);
  ws34[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 192U);
  ws34[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 192U);
  ws34[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 192U);
  ws34[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 192U);
  ws34[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 224U);
  ws34[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 224U);
  ws34[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 224U);
  ws34[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 224U);
  Lib_IntVector_Intrinsics_vec256 v08 = ws34[0U];
  Lib_IntVector_Intrinsics_vec256 v18 = ws34[1U];
  Lib_IntVector_Intrinsics_vec256 v28 = ws34[2U];
  Lib_IntVector_Intrinsics_vec256 v38 = ws34[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v1_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v2_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v3_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v0__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v1__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v2__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256
  v3__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256 ws01 = v0__7;
  Lib_IntVector_Intrinsics_vec256 ws112 = v2__7;
  Lib_IntVector_Intrinsics_vec256 ws212 = v1__7;
  Lib_IntVector_Intrinsics_vec256 ws35 = v3__7;
  Lib_IntVector_Intrinsics_vec256 v09 = ws34[4U];
  Lib_IntVector_Intrinsics_vec256 v19 = ws34[5U];
  Lib_IntVector_Intrinsics_vec256 v29 = ws34[6U];
  Lib_IntVector_Intrinsics_vec256 v39 = ws34[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v1_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v2_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v3_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v0__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v1__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v2__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256
  v3__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256 ws41 = v0__8;
  Lib_IntVector_Intrinsics_vec256 ws51 = v2__8;
  Lib_IntVector_Intrinsics_vec256 ws61 = v1__8;
  Lib_IntVector_Intrinsics_vec256 ws71 = v3__8;
  Lib_IntVector_Intrinsics_vec256 v010 = ws34[8U];
  Lib_IntVector_Intrinsics_vec256 v110 = ws34[9U];
  Lib_IntVector_Intrinsics_vec256 v210 = ws34[10U];
  Lib_IntVector_Intrinsics_vec256 v310 = ws34[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v1_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v2_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v3_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v0__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v1__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v2__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256
  v3__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256 ws81 = v0__9;
  Lib_IntVector_Intrinsics_vec256 ws91 = v2__9;
  Lib_IntVector_Intrinsics_vec256 ws101 = v1__9;
  Lib_IntVector_Intrinsics_vec256 ws113 = v3__9;
  Lib_IntVector_Intrinsics_vec256 v011 = ws34[12U];
  Lib_IntVector_Intrinsics_vec256 v111 = ws34[13U];
  Lib_IntVector_Intrinsics_vec256 v211 = ws34[14U];
  Lib_IntVector_Intrinsics_vec256 v311 = ws34[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v1_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v2_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v3_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v0__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v1__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v2__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256
  v3__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256 ws121 = v0__10;
  Lib_IntVector_Intrinsics_vec256 ws131 = v2__10;
  Lib_IntVector_Intrinsics_vec256 ws141 = v1__10;
  Lib_IntVector_Intrinsics_vec256 ws151 = v3__10;
  Lib_IntVector_Intrinsics_vec256 v012 = ws34[16U];
  Lib_IntVector_Intrinsics_vec256 v112 = ws34[17U];
  Lib_IntVector_Intrinsics_vec256 v212 = ws34[18U];
  Lib_IntVector_Intrinsics_vec256 v312 = ws34[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v1_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v2_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v3_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v0__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v1__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v2__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256
  v3__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256 ws161 = v0__11;
  Lib_IntVector_Intrinsics_vec256 ws171 = v2__11;
  Lib_IntVector_Intrinsics_vec256 ws181 = v1__11;
  Lib_IntVector_Intrinsics_vec256 ws191 = v3__11;
  Lib_IntVector_Intrinsics_vec256 v013 = ws34[20U];
  Lib_IntVector_Intrinsics_vec256 v113 = ws34[21U];
  Lib_IntVector_Intrinsics_vec256 v213 = ws34[22U];
  Lib_IntVector_Intrinsics_vec256 v313 = ws34[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v1_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v2_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v3_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v0__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v1__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v2__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256
  v3__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256 ws201 = v0__12;
  Lib_IntVector_Intrinsics_vec256 ws213 = v2__12;
  Lib_IntVector_Intrinsics_vec256 ws221 = v1__12;
  Lib_IntVector_Intrinsics_vec256 ws231 = v3__12;
  Lib_IntVector_Intrinsics_vec256 v014 = ws34[24U];
  Lib_IntVector_Intrinsics_vec256 v114 = ws34[25U];
  Lib_IntVector_Intrinsics_vec256 v214 = ws34[26U];
  Lib_IntVector_Intrinsics_vec256 v314 = ws34[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v1_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v2_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v3_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v0__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v1__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v2__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256
  v3__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256 ws241 = v0__13;
  Lib_IntVector_Intrinsics_vec256 ws251 = v2__13;
  Lib_IntVector_Intrinsics_vec256 ws261 = v1__13;
  Lib_IntVector_Intrinsics_vec256 ws271 = v3__13;
  Lib_IntVector_Intrinsics_vec256 v015 = ws34[28U];
  Lib_IntVector_Intrinsics_vec256 v115 = ws34[29U];
  Lib_IntVector_Intrinsics_vec256 v215 = ws34[30U];
  Lib_IntVector_Intrinsics_vec256 v315 = ws34[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v1_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v2_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v3_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v0__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v1__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v2__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256
  v3__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256 ws281 = v0__14;
  Lib_IntVector_Intrinsics_vec256 ws291 = v2__14;
  Lib_IntVector_Intrinsics_vec256 ws301 = v1__14;
  Lib_IntVector_Intrinsics_vec256 ws311 = v3__14;
  ws34[0U] = ws01;
  ws34[1U] = ws112;
  ws34[2U] = ws212;
  ws34[3U] = ws35;
  ws34[4U] = ws41;
  ws34[5U] = ws51;
  ws34[6U] = ws61;
  ws34[7U] = ws71;
  ws34[8U] = ws81;
  ws34[9U] = ws91;
  ws34[10U] = ws101;
  ws34[11U] = ws113;
  ws34[12U] = ws121;
  ws34[13U] = ws131;
  ws34[14U] = ws141;
  ws34[15U] = ws151;
  ws34[16U] = ws161;
  ws34[17U] = ws171;
  ws34[18U] = ws181;
  ws34[19U] = ws191;
  ws34[20U] = ws201;
  ws34[21U] = ws213;
  ws34[22U] = ws221;
  ws34[23U] = ws231;
  ws34[24U] = ws241;
  ws34[25U] = ws251;
  ws34[26U] = ws261;
  ws34[27U] = ws271;
  ws34[28U] = ws281;
  ws34[29U] = ws291;
  ws34[30U] = ws301;
  ws34[31U] = ws311;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws34[i]);
  }
  for (uint32_t i0 = 0U; i0 < 24U; i0++)
  {
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____17 = s[i + 0U];
      Lib_IntVector_Intrinsics_vec256 uu____18 = s[i + 5U];
      Lib_IntVector_Intrinsics_vec256 uu____19 = s[i + 10U];
      _C[i] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____17,
          Lib_IntVector_Intrinsics_vec256_xor(uu____18,
            Lib_IntVector_Intrinsics_vec256_xor(uu____19,
              Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
    KRML_MAYBE_FOR5(i1,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____20 = _C[(i1 + 4U) % 5U];
      Lib_IntVector_Intrinsics_vec256 uu____21 = _C[(i1 + 1U) % 5U];
      Lib_IntVector_Intrinsics_vec256
      _D =
        Lib_IntVector_Intrinsics_vec256_xor(uu____20,
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____21,
              1U),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____21, 63U)));
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        s[i1 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i1 + 5U * i], _D);););
    Lib_IntVector_Intrinsics_vec256 x = s[1U];
    Lib_IntVector_Intrinsics_vec256 current = x;
    for (uint32_t i = 0U; i < 24U; i++)
    {
      uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
      uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
      Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
      Lib_IntVector_Intrinsics_vec256 uu____22 = current;
      s[_Y] =
        Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____22, r),
          Lib_IntVector_Intrinsics_vec256_shift_right64(uu____22, 64U - r));
      current = temp;
    }
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____23 = s[0U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____24 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v0 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____23,
          Lib_IntVector_Intrinsics_vec256_and(uu____24, s[2U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____25 = s[1U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____26 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v1 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____25,
          Lib_IntVector_Intrinsics_vec256_and(uu____26, s[3U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____27 = s[2U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____28 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v2 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____27,
          Lib_IntVector_Intrinsics_vec256_and(uu____28, s[4U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____29 = s[3U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____30 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v3 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____29,
          Lib_IntVector_Intrinsics_vec256_and(uu____30, s[0U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____31 = s[4U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____32 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v4 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____31,
          Lib_IntVector_Intrinsics_vec256_and(uu____32, s[1U + 5U * i]));
      s[0U + 5U * i] = v0;
      s[1U + 5U * i] = v1;
      s[2U + 5U * i] = v2;
      s[3U + 5U * i] = v3;
      s[4U + 5U * i] = v4;);
    uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i0];
    Lib_IntVector_Intrinsics_vec256 uu____33 = s[0U];
    s[0U] =
      Lib_IntVector_Intrinsics_vec256_xor(uu____33,
        Lib_IntVector_Intrinsics_vec256_load64(c));
  }
  for (uint32_t i0 = 0U; i0 < 28U / rateInBytes; i0++)
  {
    uint8_t hbuf[1024U] = { 0U };
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
    Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256
    v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
    Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256
    v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
    Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256
    v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
    Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256
    v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
    Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256
    v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
    Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256
    v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
    Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256
    v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256
    v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 32U; i++)
    {
      Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
    }
    for (uint32_t i = 0U; i < rateInBytes / 32U; i++)
    {
      uint8_t *b31 = rb.snd.snd.snd;
      uint8_t *b21 = rb.snd.snd.fst;
      uint8_t *b11 = rb.snd.fst;
      uint8_t *b01 = rb.fst;
      memcpy(b01 + i0 * rateInBytes + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
      memcpy(b11 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
      memcpy(b21 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
      memcpy(b31 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
    }
    uint32_t rem0 = rateInBytes % 32U;
    uint32_t j = rateInBytes / 32U;
    uint8_t *b31 = rb.snd.snd.snd;
    uint8_t *b21 = rb.snd.snd.fst;
    uint8_t *b11 = rb.snd.fst;
    uint8_t *b01 = rb.fst;
    memcpy(b01 + i0 * rateInBytes + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
    memcpy(b11 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
    memcpy(b21 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
    memcpy(b31 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____34 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____35 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____36 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____34,
            Lib_IntVector_Intrinsics_vec256_xor(uu____35,
              Lib_IntVector_Intrinsics_vec256_xor(uu____36,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____37 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____38 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____37,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____38,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____38, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____39 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____39,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____39, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____40 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____41 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v023 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____40,
            Lib_IntVector_Intrinsics_vec256_and(uu____41, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____42 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____43 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v123 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____42,
            Lib_IntVector_Intrinsics_vec256_and(uu____43, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____44 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____45 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v223 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____44,
            Lib_IntVector_Intrinsics_vec256_and(uu____45, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____46 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____47 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v323 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____46,
            Lib_IntVector_Intrinsics_vec256_and(uu____47, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____48 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____49 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____48,
            Lib_IntVector_Intrinsics_vec256_and(uu____49, s[1U + 5U * i]));
        s[0U + 5U * i] = v023;
        s[1U + 5U * i] = v123;
        s[2U + 5U * i] = v223;
        s[3U + 5U * i] = v323;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____50 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____50,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t remOut = 28U % rateInBytes;
  uint8_t hbuf[1024U] = { 0U };
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
  memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
  Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
  Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
  Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
  Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256
  v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
  Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
  Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
  Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
  Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
  Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
  Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
  Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256
  v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
  Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
  Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
  Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
  Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
  Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
  Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
  Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256
  v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
  Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
  Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
  Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
  Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
  Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
  Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
  Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256
  v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
  Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
  Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
  Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
  Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
  Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
  Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
  Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256
  v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
  Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
  Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
  Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
  Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
  Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
  Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
  Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256
  v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
  Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
  Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
  Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
  Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
  Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
  Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
  Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256
  v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
  Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
  Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
  Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
  Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
  Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
  Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
  Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256
  v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
  Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
  Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
  Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
  ws[0U] = ws0;
  ws[1U] = ws1;
  ws[2U] = ws2;
  ws[3U] = ws3;
  ws[4U] = ws4;
  ws[5U] = ws5;
  ws[6U] = ws6;
  ws[7U] = ws7;
  ws[8U] = ws8;
  ws[9U] = ws9;
  ws[10U] = ws10;
  ws[11U] = ws11;
  ws[12U] = ws12;
  ws[13U] = ws13;
  ws[14U] = ws14;
  ws[15U] = ws15;
  ws[16U] = ws16;
  ws[17U] = ws17;
  ws[18U] = ws18;
  ws[19U] = ws19;
  ws[20U] = ws20;
  ws[21U] = ws21;
  ws[22U] = ws22;
  ws[23U] = ws23;
  ws[24U] = ws24;
  ws[25U] = ws25;
  ws[26U] = ws26;
  ws[27U] = ws27;
  ws[28U] = ws28;
  ws[29U] = ws29;
  ws[30U] = ws30;
  ws[31U] = ws31;
  for (uint32_t i = 0U; i < 32U; i++)
  {
    Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
  }
  for (uint32_t i = 0U; i < remOut / 32U; i++)
  {
    uint8_t *b3 = rb.snd.snd.snd;
    uint8_t *b2 = rb.snd.snd.fst;
    uint8_t *b1 = rb.snd.fst;
    uint8_t *b0 = rb.fst;
    memcpy(b0 + 28U - remOut + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
    memcpy(b1 + 28U - remOut + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
    memcpy(b2 + 28U - remOut + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
    memcpy(b3 + 28U - remOut + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
  }
  uint32_t rem0 = remOut % 32U;
  uint32_t j = remOut / 32U;
  uint8_t *b3 = rb.snd.snd.snd;
  uint8_t *b2 = rb.snd.snd.fst;
  uint8_t *b1 = rb.snd.fst;
  uint8_t *b0 = rb.fst;
  memcpy(b0 + 28U - remOut + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
  memcpy(b1 + 28U - remOut + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
  memcpy(b2 + 28U - remOut + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
  memcpy(b3 + 28U - remOut + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
}

void
Hacl_Hash_SHA3_Simd256_sha3_256(
  uint32_t inputByteLen,
  uint8_t *input0,
  uint8_t *input1,
  uint8_t *input2,
  uint8_t *input3,
  uint8_t *output0,
  uint8_t *output1,
  uint8_t *output2,
  uint8_t *output3
)
{
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  ib = { .fst = input0, .snd = { .fst = input1, .snd = { .fst = input2, .snd = input3 } } };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  rb = { .fst = output0, .snd = { .fst = output1, .snd = { .fst = output2, .snd = output3 } } };
  uint32_t rateInBytes = 136U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 s[25U] KRML_POST_ALIGN(32) = { 0U };
  for (uint32_t i0 = 0U; i0 < inputByteLen / rateInBytes; i0++)
  {
    uint8_t b00[256U] = { 0U };
    uint8_t b10[256U] = { 0U };
    uint8_t b20[256U] = { 0U };
    uint8_t b30[256U] = { 0U };
    K____uint8_t___uint8_t____K____uint8_t___uint8_t_
    b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
    uint8_t *b31 = ib.snd.snd.snd;
    uint8_t *b21 = ib.snd.snd.fst;
    uint8_t *b11 = ib.snd.fst;
    uint8_t *b01 = ib.fst;
    uint8_t *bl3 = b_.snd.snd.snd;
    uint8_t *bl2 = b_.snd.snd.fst;
    uint8_t *bl1 = b_.snd.fst;
    uint8_t *bl0 = b_.fst;
    memcpy(bl0, b01 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl1, b11 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl2, b21 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl3, b31 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    uint8_t *b3 = b_.snd.snd.snd;
    uint8_t *b2 = b_.snd.snd.fst;
    uint8_t *b1 = b_.snd.fst;
    uint8_t *b0 = b_.fst;
    ws[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0);
    ws[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1);
    ws[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2);
    ws[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3);
    ws[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 32U);
    ws[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 32U);
    ws[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 32U);
    ws[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 32U);
    ws[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 64U);
    ws[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 64U);
    ws[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 64U);
    ws[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 64U);
    ws[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 96U);
    ws[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 96U);
    ws[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 96U);
    ws[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 96U);
    ws[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 128U);
    ws[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 128U);
    ws[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 128U);
    ws[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 128U);
    ws[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 160U);
    ws[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 160U);
    ws[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 160U);
    ws[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 160U);
    ws[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 192U);
    ws[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 192U);
    ws[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 192U);
    ws[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 192U);
    ws[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 224U);
    ws[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 224U);
    ws[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 224U);
    ws[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 224U);
    Lib_IntVector_Intrinsics_vec256 v00 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v10 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v20 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v30 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256
    v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__;
    Lib_IntVector_Intrinsics_vec256 v01 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v11 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v21 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v31 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256
    v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__0;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__0;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__0;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__0;
    Lib_IntVector_Intrinsics_vec256 v02 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v12 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v22 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v32 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256
    v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__1;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__1;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__1;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__1;
    Lib_IntVector_Intrinsics_vec256 v03 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v13 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v23 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v33 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256
    v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__2;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__2;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__2;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__2;
    Lib_IntVector_Intrinsics_vec256 v04 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v14 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v24 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v34 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256
    v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__3;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__3;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__3;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__3;
    Lib_IntVector_Intrinsics_vec256 v05 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v15 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v25 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v35 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256
    v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__4;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__4;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__4;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__4;
    Lib_IntVector_Intrinsics_vec256 v06 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v16 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v26 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v36 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256
    v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__5;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__5;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__5;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__5;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256
    v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__6;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__6;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__6;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__6;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 25U; i++)
    {
      s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws[i]);
    }
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____0 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____1 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____2 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____0,
            Lib_IntVector_Intrinsics_vec256_xor(uu____1,
              Lib_IntVector_Intrinsics_vec256_xor(uu____2,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____3 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____4 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____3,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____4,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____4, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____5 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____5,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____5, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____6 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____7 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v07 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____6,
            Lib_IntVector_Intrinsics_vec256_and(uu____7, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____8 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____9 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v17 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____8,
            Lib_IntVector_Intrinsics_vec256_and(uu____9, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____10 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____11 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v27 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____10,
            Lib_IntVector_Intrinsics_vec256_and(uu____11, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____12 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____13 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v37 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____12,
            Lib_IntVector_Intrinsics_vec256_and(uu____13, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____14 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____15 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____14,
            Lib_IntVector_Intrinsics_vec256_and(uu____15, s[1U + 5U * i]));
        s[0U + 5U * i] = v07;
        s[1U + 5U * i] = v17;
        s[2U + 5U * i] = v27;
        s[3U + 5U * i] = v37;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____16 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____16,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t rem = inputByteLen % rateInBytes;
  uint8_t b00[256U] = { 0U };
  uint8_t b10[256U] = { 0U };
  uint8_t b20[256U] = { 0U };
  uint8_t b30[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
  uint32_t rem1 = inputByteLen % rateInBytes;
  uint8_t *b32 = ib.snd.snd.snd;
  uint8_t *b22 = ib.snd.snd.fst;
  uint8_t *b12 = ib.snd.fst;
  uint8_t *b02 = ib.fst;
  uint8_t *bl3 = b_.snd.snd.snd;
  uint8_t *bl2 = b_.snd.snd.fst;
  uint8_t *bl1 = b_.snd.fst;
  uint8_t *bl0 = b_.fst;
  memcpy(bl0, b02 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl1, b12 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl2, b22 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl3, b32 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  uint8_t *b33 = b_.snd.snd.snd;
  uint8_t *b23 = b_.snd.snd.fst;
  uint8_t *b13 = b_.snd.fst;
  uint8_t *b03 = b_.fst;
  b03[rem] = 0x06U;
  b13[rem] = 0x06U;
  b23[rem] = 0x06U;
  b33[rem] = 0x06U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws32[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b34 = b_.snd.snd.snd;
  uint8_t *b24 = b_.snd.snd.fst;
  uint8_t *b14 = b_.snd.fst;
  uint8_t *b04 = b_.fst;
  ws32[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04);
  ws32[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14);
  ws32[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24);
  ws32[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34);
  ws32[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 32U);
  ws32[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 32U);
  ws32[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 32U);
  ws32[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 32U);
  ws32[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 64U);
  ws32[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 64U);
  ws32[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 64U);
  ws32[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 64U);
  ws32[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 96U);
  ws32[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 96U);
  ws32[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 96U);
  ws32[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 96U);
  ws32[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 128U);
  ws32[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 128U);
  ws32[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 128U);
  ws32[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 128U);
  ws32[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 160U);
  ws32[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 160U);
  ws32[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 160U);
  ws32[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 160U);
  ws32[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 192U);
  ws32[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 192U);
  ws32[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 192U);
  ws32[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 192U);
  ws32[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 224U);
  ws32[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 224U);
  ws32[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 224U);
  ws32[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 224U);
  Lib_IntVector_Intrinsics_vec256 v00 = ws32[0U];
  Lib_IntVector_Intrinsics_vec256 v10 = ws32[1U];
  Lib_IntVector_Intrinsics_vec256 v20 = ws32[2U];
  Lib_IntVector_Intrinsics_vec256 v30 = ws32[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256
  v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256 ws00 = v0__;
  Lib_IntVector_Intrinsics_vec256 ws110 = v2__;
  Lib_IntVector_Intrinsics_vec256 ws210 = v1__;
  Lib_IntVector_Intrinsics_vec256 ws33 = v3__;
  Lib_IntVector_Intrinsics_vec256 v01 = ws32[4U];
  Lib_IntVector_Intrinsics_vec256 v11 = ws32[5U];
  Lib_IntVector_Intrinsics_vec256 v21 = ws32[6U];
  Lib_IntVector_Intrinsics_vec256 v31 = ws32[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256
  v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256 ws40 = v0__0;
  Lib_IntVector_Intrinsics_vec256 ws50 = v2__0;
  Lib_IntVector_Intrinsics_vec256 ws60 = v1__0;
  Lib_IntVector_Intrinsics_vec256 ws70 = v3__0;
  Lib_IntVector_Intrinsics_vec256 v02 = ws32[8U];
  Lib_IntVector_Intrinsics_vec256 v12 = ws32[9U];
  Lib_IntVector_Intrinsics_vec256 v22 = ws32[10U];
  Lib_IntVector_Intrinsics_vec256 v32 = ws32[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256
  v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256 ws80 = v0__1;
  Lib_IntVector_Intrinsics_vec256 ws90 = v2__1;
  Lib_IntVector_Intrinsics_vec256 ws100 = v1__1;
  Lib_IntVector_Intrinsics_vec256 ws111 = v3__1;
  Lib_IntVector_Intrinsics_vec256 v03 = ws32[12U];
  Lib_IntVector_Intrinsics_vec256 v13 = ws32[13U];
  Lib_IntVector_Intrinsics_vec256 v23 = ws32[14U];
  Lib_IntVector_Intrinsics_vec256 v33 = ws32[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256
  v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256 ws120 = v0__2;
  Lib_IntVector_Intrinsics_vec256 ws130 = v2__2;
  Lib_IntVector_Intrinsics_vec256 ws140 = v1__2;
  Lib_IntVector_Intrinsics_vec256 ws150 = v3__2;
  Lib_IntVector_Intrinsics_vec256 v04 = ws32[16U];
  Lib_IntVector_Intrinsics_vec256 v14 = ws32[17U];
  Lib_IntVector_Intrinsics_vec256 v24 = ws32[18U];
  Lib_IntVector_Intrinsics_vec256 v34 = ws32[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256
  v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256 ws160 = v0__3;
  Lib_IntVector_Intrinsics_vec256 ws170 = v2__3;
  Lib_IntVector_Intrinsics_vec256 ws180 = v1__3;
  Lib_IntVector_Intrinsics_vec256 ws190 = v3__3;
  Lib_IntVector_Intrinsics_vec256 v05 = ws32[20U];
  Lib_IntVector_Intrinsics_vec256 v15 = ws32[21U];
  Lib_IntVector_Intrinsics_vec256 v25 = ws32[22U];
  Lib_IntVector_Intrinsics_vec256 v35 = ws32[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256
  v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256 ws200 = v0__4;
  Lib_IntVector_Intrinsics_vec256 ws211 = v2__4;
  Lib_IntVector_Intrinsics_vec256 ws220 = v1__4;
  Lib_IntVector_Intrinsics_vec256 ws230 = v3__4;
  Lib_IntVector_Intrinsics_vec256 v06 = ws32[24U];
  Lib_IntVector_Intrinsics_vec256 v16 = ws32[25U];
  Lib_IntVector_Intrinsics_vec256 v26 = ws32[26U];
  Lib_IntVector_Intrinsics_vec256 v36 = ws32[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256
  v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256 ws240 = v0__5;
  Lib_IntVector_Intrinsics_vec256 ws250 = v2__5;
  Lib_IntVector_Intrinsics_vec256 ws260 = v1__5;
  Lib_IntVector_Intrinsics_vec256 ws270 = v3__5;
  Lib_IntVector_Intrinsics_vec256 v07 = ws32[28U];
  Lib_IntVector_Intrinsics_vec256 v17 = ws32[29U];
  Lib_IntVector_Intrinsics_vec256 v27 = ws32[30U];
  Lib_IntVector_Intrinsics_vec256 v37 = ws32[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256
  v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256 ws280 = v0__6;
  Lib_IntVector_Intrinsics_vec256 ws290 = v2__6;
  Lib_IntVector_Intrinsics_vec256 ws300 = v1__6;
  Lib_IntVector_Intrinsics_vec256 ws310 = v3__6;
  ws32[0U] = ws00;
  ws32[1U] = ws110;
  ws32[2U] = ws210;
  ws32[3U] = ws33;
  ws32[4U] = ws40;
  ws32[5U] = ws50;
  ws32[6U] = ws60;
  ws32[7U] = ws70;
  ws32[8U] = ws80;
  ws32[9U] = ws90;
  ws32[10U] = ws100;
  ws32[11U] = ws111;
  ws32[12U] = ws120;
  ws32[13U] = ws130;
  ws32[14U] = ws140;
  ws32[15U] = ws150;
  ws32[16U] = ws160;
  ws32[17U] = ws170;
  ws32[18U] = ws180;
  ws32[19U] = ws190;
  ws32[20U] = ws200;
  ws32[21U] = ws211;
  ws32[22U] = ws220;
  ws32[23U] = ws230;
  ws32[24U] = ws240;
  ws32[25U] = ws250;
  ws32[26U] = ws260;
  ws32[27U] = ws270;
  ws32[28U] = ws280;
  ws32[29U] = ws290;
  ws32[30U] = ws300;
  ws32[31U] = ws310;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws32[i]);
  }
  uint8_t b05[256U] = { 0U };
  uint8_t b15[256U] = { 0U };
  uint8_t b25[256U] = { 0U };
  uint8_t b35[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b = { .fst = b05, .snd = { .fst = b15, .snd = { .fst = b25, .snd = b35 } } };
  uint8_t *b36 = b.snd.snd.snd;
  uint8_t *b26 = b.snd.snd.fst;
  uint8_t *b16 = b.snd.fst;
  uint8_t *b06 = b.fst;
  b06[rateInBytes - 1U] = 0x80U;
  b16[rateInBytes - 1U] = 0x80U;
  b26[rateInBytes - 1U] = 0x80U;
  b36[rateInBytes - 1U] = 0x80U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws34[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b37 = b.snd.snd.snd;
  uint8_t *b27 = b.snd.snd.fst;
  uint8_t *b17 = b.snd.fst;
  uint8_t *b07 = b.fst;
  ws34[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07);
  ws34[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17);
  ws34[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27);
  ws34[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37);
  ws34[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 32U);
  ws34[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 32U);
  ws34[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 32U);
  ws34[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 32U);
  ws34[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 64U);
  ws34[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 64U);
  ws34[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 64U);
  ws34[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 64U);
  ws34[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 96U);
  ws34[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 96U);
  ws34[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 96U);
  ws34[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 96U);
  ws34[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 128U);
  ws34[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 128U);
  ws34[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 128U);
  ws34[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 128U);
  ws34[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 160U);
  ws34[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 160U);
  ws34[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 160U);
  ws34[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 160U);
  ws34[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 192U);
  ws34[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 192U);
  ws34[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 192U);
  ws34[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 192U);
  ws34[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 224U);
  ws34[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 224U);
  ws34[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 224U);
  ws34[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 224U);
  Lib_IntVector_Intrinsics_vec256 v08 = ws34[0U];
  Lib_IntVector_Intrinsics_vec256 v18 = ws34[1U];
  Lib_IntVector_Intrinsics_vec256 v28 = ws34[2U];
  Lib_IntVector_Intrinsics_vec256 v38 = ws34[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v1_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v2_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v3_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v0__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v1__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v2__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256
  v3__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256 ws01 = v0__7;
  Lib_IntVector_Intrinsics_vec256 ws112 = v2__7;
  Lib_IntVector_Intrinsics_vec256 ws212 = v1__7;
  Lib_IntVector_Intrinsics_vec256 ws35 = v3__7;
  Lib_IntVector_Intrinsics_vec256 v09 = ws34[4U];
  Lib_IntVector_Intrinsics_vec256 v19 = ws34[5U];
  Lib_IntVector_Intrinsics_vec256 v29 = ws34[6U];
  Lib_IntVector_Intrinsics_vec256 v39 = ws34[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v1_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v2_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v3_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v0__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v1__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v2__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256
  v3__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256 ws41 = v0__8;
  Lib_IntVector_Intrinsics_vec256 ws51 = v2__8;
  Lib_IntVector_Intrinsics_vec256 ws61 = v1__8;
  Lib_IntVector_Intrinsics_vec256 ws71 = v3__8;
  Lib_IntVector_Intrinsics_vec256 v010 = ws34[8U];
  Lib_IntVector_Intrinsics_vec256 v110 = ws34[9U];
  Lib_IntVector_Intrinsics_vec256 v210 = ws34[10U];
  Lib_IntVector_Intrinsics_vec256 v310 = ws34[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v1_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v2_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v3_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v0__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v1__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v2__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256
  v3__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256 ws81 = v0__9;
  Lib_IntVector_Intrinsics_vec256 ws91 = v2__9;
  Lib_IntVector_Intrinsics_vec256 ws101 = v1__9;
  Lib_IntVector_Intrinsics_vec256 ws113 = v3__9;
  Lib_IntVector_Intrinsics_vec256 v011 = ws34[12U];
  Lib_IntVector_Intrinsics_vec256 v111 = ws34[13U];
  Lib_IntVector_Intrinsics_vec256 v211 = ws34[14U];
  Lib_IntVector_Intrinsics_vec256 v311 = ws34[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v1_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v2_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v3_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v0__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v1__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v2__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256
  v3__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256 ws121 = v0__10;
  Lib_IntVector_Intrinsics_vec256 ws131 = v2__10;
  Lib_IntVector_Intrinsics_vec256 ws141 = v1__10;
  Lib_IntVector_Intrinsics_vec256 ws151 = v3__10;
  Lib_IntVector_Intrinsics_vec256 v012 = ws34[16U];
  Lib_IntVector_Intrinsics_vec256 v112 = ws34[17U];
  Lib_IntVector_Intrinsics_vec256 v212 = ws34[18U];
  Lib_IntVector_Intrinsics_vec256 v312 = ws34[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v1_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v2_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v3_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v0__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v1__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v2__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256
  v3__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256 ws161 = v0__11;
  Lib_IntVector_Intrinsics_vec256 ws171 = v2__11;
  Lib_IntVector_Intrinsics_vec256 ws181 = v1__11;
  Lib_IntVector_Intrinsics_vec256 ws191 = v3__11;
  Lib_IntVector_Intrinsics_vec256 v013 = ws34[20U];
  Lib_IntVector_Intrinsics_vec256 v113 = ws34[21U];
  Lib_IntVector_Intrinsics_vec256 v213 = ws34[22U];
  Lib_IntVector_Intrinsics_vec256 v313 = ws34[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v1_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v2_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v3_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v0__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v1__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v2__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256
  v3__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256 ws201 = v0__12;
  Lib_IntVector_Intrinsics_vec256 ws213 = v2__12;
  Lib_IntVector_Intrinsics_vec256 ws221 = v1__12;
  Lib_IntVector_Intrinsics_vec256 ws231 = v3__12;
  Lib_IntVector_Intrinsics_vec256 v014 = ws34[24U];
  Lib_IntVector_Intrinsics_vec256 v114 = ws34[25U];
  Lib_IntVector_Intrinsics_vec256 v214 = ws34[26U];
  Lib_IntVector_Intrinsics_vec256 v314 = ws34[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v1_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v2_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v3_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v0__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v1__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v2__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256
  v3__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256 ws241 = v0__13;
  Lib_IntVector_Intrinsics_vec256 ws251 = v2__13;
  Lib_IntVector_Intrinsics_vec256 ws261 = v1__13;
  Lib_IntVector_Intrinsics_vec256 ws271 = v3__13;
  Lib_IntVector_Intrinsics_vec256 v015 = ws34[28U];
  Lib_IntVector_Intrinsics_vec256 v115 = ws34[29U];
  Lib_IntVector_Intrinsics_vec256 v215 = ws34[30U];
  Lib_IntVector_Intrinsics_vec256 v315 = ws34[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v1_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v2_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v3_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v0__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v1__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v2__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256
  v3__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256 ws281 = v0__14;
  Lib_IntVector_Intrinsics_vec256 ws291 = v2__14;
  Lib_IntVector_Intrinsics_vec256 ws301 = v1__14;
  Lib_IntVector_Intrinsics_vec256 ws311 = v3__14;
  ws34[0U] = ws01;
  ws34[1U] = ws112;
  ws34[2U] = ws212;
  ws34[3U] = ws35;
  ws34[4U] = ws41;
  ws34[5U] = ws51;
  ws34[6U] = ws61;
  ws34[7U] = ws71;
  ws34[8U] = ws81;
  ws34[9U] = ws91;
  ws34[10U] = ws101;
  ws34[11U] = ws113;
  ws34[12U] = ws121;
  ws34[13U] = ws131;
  ws34[14U] = ws141;
  ws34[15U] = ws151;
  ws34[16U] = ws161;
  ws34[17U] = ws171;
  ws34[18U] = ws181;
  ws34[19U] = ws191;
  ws34[20U] = ws201;
  ws34[21U] = ws213;
  ws34[22U] = ws221;
  ws34[23U] = ws231;
  ws34[24U] = ws241;
  ws34[25U] = ws251;
  ws34[26U] = ws261;
  ws34[27U] = ws271;
  ws34[28U] = ws281;
  ws34[29U] = ws291;
  ws34[30U] = ws301;
  ws34[31U] = ws311;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws34[i]);
  }
  for (uint32_t i0 = 0U; i0 < 24U; i0++)
  {
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____17 = s[i + 0U];
      Lib_IntVector_Intrinsics_vec256 uu____18 = s[i + 5U];
      Lib_IntVector_Intrinsics_vec256 uu____19 = s[i + 10U];
      _C[i] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____17,
          Lib_IntVector_Intrinsics_vec256_xor(uu____18,
            Lib_IntVector_Intrinsics_vec256_xor(uu____19,
              Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
    KRML_MAYBE_FOR5(i1,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____20 = _C[(i1 + 4U) % 5U];
      Lib_IntVector_Intrinsics_vec256 uu____21 = _C[(i1 + 1U) % 5U];
      Lib_IntVector_Intrinsics_vec256
      _D =
        Lib_IntVector_Intrinsics_vec256_xor(uu____20,
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____21,
              1U),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____21, 63U)));
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        s[i1 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i1 + 5U * i], _D);););
    Lib_IntVector_Intrinsics_vec256 x = s[1U];
    Lib_IntVector_Intrinsics_vec256 current = x;
    for (uint32_t i = 0U; i < 24U; i++)
    {
      uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
      uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
      Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
      Lib_IntVector_Intrinsics_vec256 uu____22 = current;
      s[_Y] =
        Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____22, r),
          Lib_IntVector_Intrinsics_vec256_shift_right64(uu____22, 64U - r));
      current = temp;
    }
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____23 = s[0U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____24 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v0 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____23,
          Lib_IntVector_Intrinsics_vec256_and(uu____24, s[2U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____25 = s[1U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____26 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v1 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____25,
          Lib_IntVector_Intrinsics_vec256_and(uu____26, s[3U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____27 = s[2U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____28 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v2 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____27,
          Lib_IntVector_Intrinsics_vec256_and(uu____28, s[4U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____29 = s[3U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____30 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v3 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____29,
          Lib_IntVector_Intrinsics_vec256_and(uu____30, s[0U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____31 = s[4U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____32 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v4 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____31,
          Lib_IntVector_Intrinsics_vec256_and(uu____32, s[1U + 5U * i]));
      s[0U + 5U * i] = v0;
      s[1U + 5U * i] = v1;
      s[2U + 5U * i] = v2;
      s[3U + 5U * i] = v3;
      s[4U + 5U * i] = v4;);
    uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i0];
    Lib_IntVector_Intrinsics_vec256 uu____33 = s[0U];
    s[0U] =
      Lib_IntVector_Intrinsics_vec256_xor(uu____33,
        Lib_IntVector_Intrinsics_vec256_load64(c));
  }
  for (uint32_t i0 = 0U; i0 < 32U / rateInBytes; i0++)
  {
    uint8_t hbuf[1024U] = { 0U };
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
    Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256
    v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
    Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256
    v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
    Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256
    v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
    Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256
    v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
    Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256
    v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
    Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256
    v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
    Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256
    v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256
    v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 32U; i++)
    {
      Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
    }
    for (uint32_t i = 0U; i < rateInBytes / 32U; i++)
    {
      uint8_t *b31 = rb.snd.snd.snd;
      uint8_t *b21 = rb.snd.snd.fst;
      uint8_t *b11 = rb.snd.fst;
      uint8_t *b01 = rb.fst;
      memcpy(b01 + i0 * rateInBytes + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
      memcpy(b11 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
      memcpy(b21 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
      memcpy(b31 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
    }
    uint32_t rem0 = rateInBytes % 32U;
    uint32_t j = rateInBytes / 32U;
    uint8_t *b31 = rb.snd.snd.snd;
    uint8_t *b21 = rb.snd.snd.fst;
    uint8_t *b11 = rb.snd.fst;
    uint8_t *b01 = rb.fst;
    memcpy(b01 + i0 * rateInBytes + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
    memcpy(b11 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
    memcpy(b21 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
    memcpy(b31 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____34 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____35 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____36 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____34,
            Lib_IntVector_Intrinsics_vec256_xor(uu____35,
              Lib_IntVector_Intrinsics_vec256_xor(uu____36,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____37 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____38 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____37,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____38,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____38, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____39 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____39,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____39, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____40 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____41 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v023 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____40,
            Lib_IntVector_Intrinsics_vec256_and(uu____41, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____42 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____43 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v123 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____42,
            Lib_IntVector_Intrinsics_vec256_and(uu____43, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____44 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____45 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v223 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____44,
            Lib_IntVector_Intrinsics_vec256_and(uu____45, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____46 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____47 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v323 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____46,
            Lib_IntVector_Intrinsics_vec256_and(uu____47, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____48 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____49 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____48,
            Lib_IntVector_Intrinsics_vec256_and(uu____49, s[1U + 5U * i]));
        s[0U + 5U * i] = v023;
        s[1U + 5U * i] = v123;
        s[2U + 5U * i] = v223;
        s[3U + 5U * i] = v323;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____50 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____50,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t remOut = 32U % rateInBytes;
  uint8_t hbuf[1024U] = { 0U };
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
  memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
  Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
  Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
  Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
  Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256
  v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
  Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
  Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
  Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
  Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
  Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
  Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
  Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256
  v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
  Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
  Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
  Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
  Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
  Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
  Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
  Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256
  v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
  Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
  Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
  Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
  Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
  Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
  Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
  Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256
  v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
  Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
  Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
  Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
  Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
  Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
  Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
  Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256
  v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
  Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
  Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
  Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
  Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
  Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
  Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
  Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256
  v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
  Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
  Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
  Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
  Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
  Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
  Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
  Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256
  v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
  Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
  Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
  Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
  Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
  Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
  Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
  Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256
  v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
  Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
  Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
  Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
  ws[0U] = ws0;
  ws[1U] = ws1;
  ws[2U] = ws2;
  ws[3U] = ws3;
  ws[4U] = ws4;
  ws[5U] = ws5;
  ws[6U] = ws6;
  ws[7U] = ws7;
  ws[8U] = ws8;
  ws[9U] = ws9;
  ws[10U] = ws10;
  ws[11U] = ws11;
  ws[12U] = ws12;
  ws[13U] = ws13;
  ws[14U] = ws14;
  ws[15U] = ws15;
  ws[16U] = ws16;
  ws[17U] = ws17;
  ws[18U] = ws18;
  ws[19U] = ws19;
  ws[20U] = ws20;
  ws[21U] = ws21;
  ws[22U] = ws22;
  ws[23U] = ws23;
  ws[24U] = ws24;
  ws[25U] = ws25;
  ws[26U] = ws26;
  ws[27U] = ws27;
  ws[28U] = ws28;
  ws[29U] = ws29;
  ws[30U] = ws30;
  ws[31U] = ws31;
  for (uint32_t i = 0U; i < 32U; i++)
  {
    Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
  }
  for (uint32_t i = 0U; i < remOut / 32U; i++)
  {
    uint8_t *b3 = rb.snd.snd.snd;
    uint8_t *b2 = rb.snd.snd.fst;
    uint8_t *b1 = rb.snd.fst;
    uint8_t *b0 = rb.fst;
    memcpy(b0 + 32U - remOut + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
    memcpy(b1 + 32U - remOut + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
    memcpy(b2 + 32U - remOut + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
    memcpy(b3 + 32U - remOut + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
  }
  uint32_t rem0 = remOut % 32U;
  uint32_t j = remOut / 32U;
  uint8_t *b3 = rb.snd.snd.snd;
  uint8_t *b2 = rb.snd.snd.fst;
  uint8_t *b1 = rb.snd.fst;
  uint8_t *b0 = rb.fst;
  memcpy(b0 + 32U - remOut + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
  memcpy(b1 + 32U - remOut + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
  memcpy(b2 + 32U - remOut + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
  memcpy(b3 + 32U - remOut + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
}

void
Hacl_Hash_SHA3_Simd256_sha3_384(
  uint32_t inputByteLen,
  uint8_t *input0,
  uint8_t *input1,
  uint8_t *input2,
  uint8_t *input3,
  uint8_t *output0,
  uint8_t *output1,
  uint8_t *output2,
  uint8_t *output3
)
{
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  ib = { .fst = input0, .snd = { .fst = input1, .snd = { .fst = input2, .snd = input3 } } };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  rb = { .fst = output0, .snd = { .fst = output1, .snd = { .fst = output2, .snd = output3 } } };
  uint32_t rateInBytes = 104U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 s[25U] KRML_POST_ALIGN(32) = { 0U };
  for (uint32_t i0 = 0U; i0 < inputByteLen / rateInBytes; i0++)
  {
    uint8_t b00[256U] = { 0U };
    uint8_t b10[256U] = { 0U };
    uint8_t b20[256U] = { 0U };
    uint8_t b30[256U] = { 0U };
    K____uint8_t___uint8_t____K____uint8_t___uint8_t_
    b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
    uint8_t *b31 = ib.snd.snd.snd;
    uint8_t *b21 = ib.snd.snd.fst;
    uint8_t *b11 = ib.snd.fst;
    uint8_t *b01 = ib.fst;
    uint8_t *bl3 = b_.snd.snd.snd;
    uint8_t *bl2 = b_.snd.snd.fst;
    uint8_t *bl1 = b_.snd.fst;
    uint8_t *bl0 = b_.fst;
    memcpy(bl0, b01 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl1, b11 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl2, b21 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl3, b31 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    uint8_t *b3 = b_.snd.snd.snd;
    uint8_t *b2 = b_.snd.snd.fst;
    uint8_t *b1 = b_.snd.fst;
    uint8_t *b0 = b_.fst;
    ws[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0);
    ws[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1);
    ws[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2);
    ws[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3);
    ws[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 32U);
    ws[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 32U);
    ws[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 32U);
    ws[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 32U);
    ws[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 64U);
    ws[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 64U);
    ws[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 64U);
    ws[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 64U);
    ws[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 96U);
    ws[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 96U);
    ws[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 96U);
    ws[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 96U);
    ws[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 128U);
    ws[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 128U);
    ws[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 128U);
    ws[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 128U);
    ws[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 160U);
    ws[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 160U);
    ws[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 160U);
    ws[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 160U);
    ws[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 192U);
    ws[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 192U);
    ws[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 192U);
    ws[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 192U);
    ws[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 224U);
    ws[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 224U);
    ws[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 224U);
    ws[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 224U);
    Lib_IntVector_Intrinsics_vec256 v00 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v10 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v20 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v30 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256
    v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__;
    Lib_IntVector_Intrinsics_vec256 v01 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v11 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v21 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v31 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256
    v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__0;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__0;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__0;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__0;
    Lib_IntVector_Intrinsics_vec256 v02 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v12 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v22 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v32 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256
    v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__1;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__1;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__1;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__1;
    Lib_IntVector_Intrinsics_vec256 v03 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v13 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v23 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v33 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256
    v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__2;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__2;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__2;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__2;
    Lib_IntVector_Intrinsics_vec256 v04 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v14 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v24 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v34 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256
    v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__3;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__3;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__3;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__3;
    Lib_IntVector_Intrinsics_vec256 v05 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v15 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v25 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v35 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256
    v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__4;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__4;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__4;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__4;
    Lib_IntVector_Intrinsics_vec256 v06 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v16 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v26 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v36 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256
    v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__5;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__5;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__5;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__5;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256
    v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__6;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__6;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__6;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__6;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 25U; i++)
    {
      s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws[i]);
    }
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____0 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____1 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____2 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____0,
            Lib_IntVector_Intrinsics_vec256_xor(uu____1,
              Lib_IntVector_Intrinsics_vec256_xor(uu____2,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____3 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____4 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____3,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____4,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____4, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____5 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____5,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____5, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____6 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____7 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v07 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____6,
            Lib_IntVector_Intrinsics_vec256_and(uu____7, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____8 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____9 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v17 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____8,
            Lib_IntVector_Intrinsics_vec256_and(uu____9, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____10 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____11 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v27 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____10,
            Lib_IntVector_Intrinsics_vec256_and(uu____11, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____12 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____13 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v37 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____12,
            Lib_IntVector_Intrinsics_vec256_and(uu____13, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____14 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____15 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____14,
            Lib_IntVector_Intrinsics_vec256_and(uu____15, s[1U + 5U * i]));
        s[0U + 5U * i] = v07;
        s[1U + 5U * i] = v17;
        s[2U + 5U * i] = v27;
        s[3U + 5U * i] = v37;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____16 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____16,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t rem = inputByteLen % rateInBytes;
  uint8_t b00[256U] = { 0U };
  uint8_t b10[256U] = { 0U };
  uint8_t b20[256U] = { 0U };
  uint8_t b30[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
  uint32_t rem1 = inputByteLen % rateInBytes;
  uint8_t *b32 = ib.snd.snd.snd;
  uint8_t *b22 = ib.snd.snd.fst;
  uint8_t *b12 = ib.snd.fst;
  uint8_t *b02 = ib.fst;
  uint8_t *bl3 = b_.snd.snd.snd;
  uint8_t *bl2 = b_.snd.snd.fst;
  uint8_t *bl1 = b_.snd.fst;
  uint8_t *bl0 = b_.fst;
  memcpy(bl0, b02 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl1, b12 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl2, b22 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl3, b32 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  uint8_t *b33 = b_.snd.snd.snd;
  uint8_t *b23 = b_.snd.snd.fst;
  uint8_t *b13 = b_.snd.fst;
  uint8_t *b03 = b_.fst;
  b03[rem] = 0x06U;
  b13[rem] = 0x06U;
  b23[rem] = 0x06U;
  b33[rem] = 0x06U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws32[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b34 = b_.snd.snd.snd;
  uint8_t *b24 = b_.snd.snd.fst;
  uint8_t *b14 = b_.snd.fst;
  uint8_t *b04 = b_.fst;
  ws32[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04);
  ws32[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14);
  ws32[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24);
  ws32[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34);
  ws32[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 32U);
  ws32[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 32U);
  ws32[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 32U);
  ws32[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 32U);
  ws32[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 64U);
  ws32[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 64U);
  ws32[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 64U);
  ws32[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 64U);
  ws32[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 96U);
  ws32[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 96U);
  ws32[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 96U);
  ws32[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 96U);
  ws32[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 128U);
  ws32[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 128U);
  ws32[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 128U);
  ws32[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 128U);
  ws32[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 160U);
  ws32[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 160U);
  ws32[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 160U);
  ws32[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 160U);
  ws32[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 192U);
  ws32[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 192U);
  ws32[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 192U);
  ws32[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 192U);
  ws32[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 224U);
  ws32[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 224U);
  ws32[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 224U);
  ws32[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 224U);
  Lib_IntVector_Intrinsics_vec256 v00 = ws32[0U];
  Lib_IntVector_Intrinsics_vec256 v10 = ws32[1U];
  Lib_IntVector_Intrinsics_vec256 v20 = ws32[2U];
  Lib_IntVector_Intrinsics_vec256 v30 = ws32[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256
  v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256 ws00 = v0__;
  Lib_IntVector_Intrinsics_vec256 ws110 = v2__;
  Lib_IntVector_Intrinsics_vec256 ws210 = v1__;
  Lib_IntVector_Intrinsics_vec256 ws33 = v3__;
  Lib_IntVector_Intrinsics_vec256 v01 = ws32[4U];
  Lib_IntVector_Intrinsics_vec256 v11 = ws32[5U];
  Lib_IntVector_Intrinsics_vec256 v21 = ws32[6U];
  Lib_IntVector_Intrinsics_vec256 v31 = ws32[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256
  v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256 ws40 = v0__0;
  Lib_IntVector_Intrinsics_vec256 ws50 = v2__0;
  Lib_IntVector_Intrinsics_vec256 ws60 = v1__0;
  Lib_IntVector_Intrinsics_vec256 ws70 = v3__0;
  Lib_IntVector_Intrinsics_vec256 v02 = ws32[8U];
  Lib_IntVector_Intrinsics_vec256 v12 = ws32[9U];
  Lib_IntVector_Intrinsics_vec256 v22 = ws32[10U];
  Lib_IntVector_Intrinsics_vec256 v32 = ws32[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256
  v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256 ws80 = v0__1;
  Lib_IntVector_Intrinsics_vec256 ws90 = v2__1;
  Lib_IntVector_Intrinsics_vec256 ws100 = v1__1;
  Lib_IntVector_Intrinsics_vec256 ws111 = v3__1;
  Lib_IntVector_Intrinsics_vec256 v03 = ws32[12U];
  Lib_IntVector_Intrinsics_vec256 v13 = ws32[13U];
  Lib_IntVector_Intrinsics_vec256 v23 = ws32[14U];
  Lib_IntVector_Intrinsics_vec256 v33 = ws32[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256
  v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256 ws120 = v0__2;
  Lib_IntVector_Intrinsics_vec256 ws130 = v2__2;
  Lib_IntVector_Intrinsics_vec256 ws140 = v1__2;
  Lib_IntVector_Intrinsics_vec256 ws150 = v3__2;
  Lib_IntVector_Intrinsics_vec256 v04 = ws32[16U];
  Lib_IntVector_Intrinsics_vec256 v14 = ws32[17U];
  Lib_IntVector_Intrinsics_vec256 v24 = ws32[18U];
  Lib_IntVector_Intrinsics_vec256 v34 = ws32[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256
  v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256 ws160 = v0__3;
  Lib_IntVector_Intrinsics_vec256 ws170 = v2__3;
  Lib_IntVector_Intrinsics_vec256 ws180 = v1__3;
  Lib_IntVector_Intrinsics_vec256 ws190 = v3__3;
  Lib_IntVector_Intrinsics_vec256 v05 = ws32[20U];
  Lib_IntVector_Intrinsics_vec256 v15 = ws32[21U];
  Lib_IntVector_Intrinsics_vec256 v25 = ws32[22U];
  Lib_IntVector_Intrinsics_vec256 v35 = ws32[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256
  v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256 ws200 = v0__4;
  Lib_IntVector_Intrinsics_vec256 ws211 = v2__4;
  Lib_IntVector_Intrinsics_vec256 ws220 = v1__4;
  Lib_IntVector_Intrinsics_vec256 ws230 = v3__4;
  Lib_IntVector_Intrinsics_vec256 v06 = ws32[24U];
  Lib_IntVector_Intrinsics_vec256 v16 = ws32[25U];
  Lib_IntVector_Intrinsics_vec256 v26 = ws32[26U];
  Lib_IntVector_Intrinsics_vec256 v36 = ws32[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256
  v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256 ws240 = v0__5;
  Lib_IntVector_Intrinsics_vec256 ws250 = v2__5;
  Lib_IntVector_Intrinsics_vec256 ws260 = v1__5;
  Lib_IntVector_Intrinsics_vec256 ws270 = v3__5;
  Lib_IntVector_Intrinsics_vec256 v07 = ws32[28U];
  Lib_IntVector_Intrinsics_vec256 v17 = ws32[29U];
  Lib_IntVector_Intrinsics_vec256 v27 = ws32[30U];
  Lib_IntVector_Intrinsics_vec256 v37 = ws32[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256
  v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256 ws280 = v0__6;
  Lib_IntVector_Intrinsics_vec256 ws290 = v2__6;
  Lib_IntVector_Intrinsics_vec256 ws300 = v1__6;
  Lib_IntVector_Intrinsics_vec256 ws310 = v3__6;
  ws32[0U] = ws00;
  ws32[1U] = ws110;
  ws32[2U] = ws210;
  ws32[3U] = ws33;
  ws32[4U] = ws40;
  ws32[5U] = ws50;
  ws32[6U] = ws60;
  ws32[7U] = ws70;
  ws32[8U] = ws80;
  ws32[9U] = ws90;
  ws32[10U] = ws100;
  ws32[11U] = ws111;
  ws32[12U] = ws120;
  ws32[13U] = ws130;
  ws32[14U] = ws140;
  ws32[15U] = ws150;
  ws32[16U] = ws160;
  ws32[17U] = ws170;
  ws32[18U] = ws180;
  ws32[19U] = ws190;
  ws32[20U] = ws200;
  ws32[21U] = ws211;
  ws32[22U] = ws220;
  ws32[23U] = ws230;
  ws32[24U] = ws240;
  ws32[25U] = ws250;
  ws32[26U] = ws260;
  ws32[27U] = ws270;
  ws32[28U] = ws280;
  ws32[29U] = ws290;
  ws32[30U] = ws300;
  ws32[31U] = ws310;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws32[i]);
  }
  uint8_t b05[256U] = { 0U };
  uint8_t b15[256U] = { 0U };
  uint8_t b25[256U] = { 0U };
  uint8_t b35[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b = { .fst = b05, .snd = { .fst = b15, .snd = { .fst = b25, .snd = b35 } } };
  uint8_t *b36 = b.snd.snd.snd;
  uint8_t *b26 = b.snd.snd.fst;
  uint8_t *b16 = b.snd.fst;
  uint8_t *b06 = b.fst;
  b06[rateInBytes - 1U] = 0x80U;
  b16[rateInBytes - 1U] = 0x80U;
  b26[rateInBytes - 1U] = 0x80U;
  b36[rateInBytes - 1U] = 0x80U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws34[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b37 = b.snd.snd.snd;
  uint8_t *b27 = b.snd.snd.fst;
  uint8_t *b17 = b.snd.fst;
  uint8_t *b07 = b.fst;
  ws34[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07);
  ws34[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17);
  ws34[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27);
  ws34[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37);
  ws34[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 32U);
  ws34[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 32U);
  ws34[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 32U);
  ws34[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 32U);
  ws34[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 64U);
  ws34[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 64U);
  ws34[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 64U);
  ws34[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 64U);
  ws34[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 96U);
  ws34[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 96U);
  ws34[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 96U);
  ws34[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 96U);
  ws34[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 128U);
  ws34[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 128U);
  ws34[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 128U);
  ws34[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 128U);
  ws34[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 160U);
  ws34[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 160U);
  ws34[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 160U);
  ws34[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 160U);
  ws34[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 192U);
  ws34[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 192U);
  ws34[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 192U);
  ws34[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 192U);
  ws34[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 224U);
  ws34[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 224U);
  ws34[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 224U);
  ws34[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 224U);
  Lib_IntVector_Intrinsics_vec256 v08 = ws34[0U];
  Lib_IntVector_Intrinsics_vec256 v18 = ws34[1U];
  Lib_IntVector_Intrinsics_vec256 v28 = ws34[2U];
  Lib_IntVector_Intrinsics_vec256 v38 = ws34[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v1_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v2_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v3_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v0__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v1__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v2__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256
  v3__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256 ws01 = v0__7;
  Lib_IntVector_Intrinsics_vec256 ws112 = v2__7;
  Lib_IntVector_Intrinsics_vec256 ws212 = v1__7;
  Lib_IntVector_Intrinsics_vec256 ws35 = v3__7;
  Lib_IntVector_Intrinsics_vec256 v09 = ws34[4U];
  Lib_IntVector_Intrinsics_vec256 v19 = ws34[5U];
  Lib_IntVector_Intrinsics_vec256 v29 = ws34[6U];
  Lib_IntVector_Intrinsics_vec256 v39 = ws34[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v1_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v2_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v3_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v0__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v1__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v2__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256
  v3__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256 ws41 = v0__8;
  Lib_IntVector_Intrinsics_vec256 ws51 = v2__8;
  Lib_IntVector_Intrinsics_vec256 ws61 = v1__8;
  Lib_IntVector_Intrinsics_vec256 ws71 = v3__8;
  Lib_IntVector_Intrinsics_vec256 v010 = ws34[8U];
  Lib_IntVector_Intrinsics_vec256 v110 = ws34[9U];
  Lib_IntVector_Intrinsics_vec256 v210 = ws34[10U];
  Lib_IntVector_Intrinsics_vec256 v310 = ws34[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v1_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v2_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v3_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v0__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v1__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v2__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256
  v3__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256 ws81 = v0__9;
  Lib_IntVector_Intrinsics_vec256 ws91 = v2__9;
  Lib_IntVector_Intrinsics_vec256 ws101 = v1__9;
  Lib_IntVector_Intrinsics_vec256 ws113 = v3__9;
  Lib_IntVector_Intrinsics_vec256 v011 = ws34[12U];
  Lib_IntVector_Intrinsics_vec256 v111 = ws34[13U];
  Lib_IntVector_Intrinsics_vec256 v211 = ws34[14U];
  Lib_IntVector_Intrinsics_vec256 v311 = ws34[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v1_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v2_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v3_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v0__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v1__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v2__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256
  v3__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256 ws121 = v0__10;
  Lib_IntVector_Intrinsics_vec256 ws131 = v2__10;
  Lib_IntVector_Intrinsics_vec256 ws141 = v1__10;
  Lib_IntVector_Intrinsics_vec256 ws151 = v3__10;
  Lib_IntVector_Intrinsics_vec256 v012 = ws34[16U];
  Lib_IntVector_Intrinsics_vec256 v112 = ws34[17U];
  Lib_IntVector_Intrinsics_vec256 v212 = ws34[18U];
  Lib_IntVector_Intrinsics_vec256 v312 = ws34[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v1_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v2_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v3_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v0__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v1__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v2__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256
  v3__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256 ws161 = v0__11;
  Lib_IntVector_Intrinsics_vec256 ws171 = v2__11;
  Lib_IntVector_Intrinsics_vec256 ws181 = v1__11;
  Lib_IntVector_Intrinsics_vec256 ws191 = v3__11;
  Lib_IntVector_Intrinsics_vec256 v013 = ws34[20U];
  Lib_IntVector_Intrinsics_vec256 v113 = ws34[21U];
  Lib_IntVector_Intrinsics_vec256 v213 = ws34[22U];
  Lib_IntVector_Intrinsics_vec256 v313 = ws34[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v1_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v2_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v3_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v0__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v1__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v2__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256
  v3__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256 ws201 = v0__12;
  Lib_IntVector_Intrinsics_vec256 ws213 = v2__12;
  Lib_IntVector_Intrinsics_vec256 ws221 = v1__12;
  Lib_IntVector_Intrinsics_vec256 ws231 = v3__12;
  Lib_IntVector_Intrinsics_vec256 v014 = ws34[24U];
  Lib_IntVector_Intrinsics_vec256 v114 = ws34[25U];
  Lib_IntVector_Intrinsics_vec256 v214 = ws34[26U];
  Lib_IntVector_Intrinsics_vec256 v314 = ws34[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v1_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v2_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v3_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v0__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v1__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v2__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256
  v3__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256 ws241 = v0__13;
  Lib_IntVector_Intrinsics_vec256 ws251 = v2__13;
  Lib_IntVector_Intrinsics_vec256 ws261 = v1__13;
  Lib_IntVector_Intrinsics_vec256 ws271 = v3__13;
  Lib_IntVector_Intrinsics_vec256 v015 = ws34[28U];
  Lib_IntVector_Intrinsics_vec256 v115 = ws34[29U];
  Lib_IntVector_Intrinsics_vec256 v215 = ws34[30U];
  Lib_IntVector_Intrinsics_vec256 v315 = ws34[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v1_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v2_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v3_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v0__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v1__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v2__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256
  v3__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256 ws281 = v0__14;
  Lib_IntVector_Intrinsics_vec256 ws291 = v2__14;
  Lib_IntVector_Intrinsics_vec256 ws301 = v1__14;
  Lib_IntVector_Intrinsics_vec256 ws311 = v3__14;
  ws34[0U] = ws01;
  ws34[1U] = ws112;
  ws34[2U] = ws212;
  ws34[3U] = ws35;
  ws34[4U] = ws41;
  ws34[5U] = ws51;
  ws34[6U] = ws61;
  ws34[7U] = ws71;
  ws34[8U] = ws81;
  ws34[9U] = ws91;
  ws34[10U] = ws101;
  ws34[11U] = ws113;
  ws34[12U] = ws121;
  ws34[13U] = ws131;
  ws34[14U] = ws141;
  ws34[15U] = ws151;
  ws34[16U] = ws161;
  ws34[17U] = ws171;
  ws34[18U] = ws181;
  ws34[19U] = ws191;
  ws34[20U] = ws201;
  ws34[21U] = ws213;
  ws34[22U] = ws221;
  ws34[23U] = ws231;
  ws34[24U] = ws241;
  ws34[25U] = ws251;
  ws34[26U] = ws261;
  ws34[27U] = ws271;
  ws34[28U] = ws281;
  ws34[29U] = ws291;
  ws34[30U] = ws301;
  ws34[31U] = ws311;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws34[i]);
  }
  for (uint32_t i0 = 0U; i0 < 24U; i0++)
  {
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____17 = s[i + 0U];
      Lib_IntVector_Intrinsics_vec256 uu____18 = s[i + 5U];
      Lib_IntVector_Intrinsics_vec256 uu____19 = s[i + 10U];
      _C[i] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____17,
          Lib_IntVector_Intrinsics_vec256_xor(uu____18,
            Lib_IntVector_Intrinsics_vec256_xor(uu____19,
              Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
    KRML_MAYBE_FOR5(i1,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____20 = _C[(i1 + 4U) % 5U];
      Lib_IntVector_Intrinsics_vec256 uu____21 = _C[(i1 + 1U) % 5U];
      Lib_IntVector_Intrinsics_vec256
      _D =
        Lib_IntVector_Intrinsics_vec256_xor(uu____20,
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____21,
              1U),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____21, 63U)));
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        s[i1 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i1 + 5U * i], _D);););
    Lib_IntVector_Intrinsics_vec256 x = s[1U];
    Lib_IntVector_Intrinsics_vec256 current = x;
    for (uint32_t i = 0U; i < 24U; i++)
    {
      uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
      uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
      Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
      Lib_IntVector_Intrinsics_vec256 uu____22 = current;
      s[_Y] =
        Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____22, r),
          Lib_IntVector_Intrinsics_vec256_shift_right64(uu____22, 64U - r));
      current = temp;
    }
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____23 = s[0U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____24 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v0 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____23,
          Lib_IntVector_Intrinsics_vec256_and(uu____24, s[2U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____25 = s[1U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____26 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v1 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____25,
          Lib_IntVector_Intrinsics_vec256_and(uu____26, s[3U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____27 = s[2U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____28 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v2 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____27,
          Lib_IntVector_Intrinsics_vec256_and(uu____28, s[4U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____29 = s[3U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____30 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v3 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____29,
          Lib_IntVector_Intrinsics_vec256_and(uu____30, s[0U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____31 = s[4U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____32 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v4 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____31,
          Lib_IntVector_Intrinsics_vec256_and(uu____32, s[1U + 5U * i]));
      s[0U + 5U * i] = v0;
      s[1U + 5U * i] = v1;
      s[2U + 5U * i] = v2;
      s[3U + 5U * i] = v3;
      s[4U + 5U * i] = v4;);
    uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i0];
    Lib_IntVector_Intrinsics_vec256 uu____33 = s[0U];
    s[0U] =
      Lib_IntVector_Intrinsics_vec256_xor(uu____33,
        Lib_IntVector_Intrinsics_vec256_load64(c));
  }
  for (uint32_t i0 = 0U; i0 < 48U / rateInBytes; i0++)
  {
    uint8_t hbuf[1024U] = { 0U };
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
    Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256
    v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
    Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256
    v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
    Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256
    v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
    Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256
    v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
    Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256
    v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
    Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256
    v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
    Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256
    v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256
    v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 32U; i++)
    {
      Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
    }
    for (uint32_t i = 0U; i < rateInBytes / 32U; i++)
    {
      uint8_t *b31 = rb.snd.snd.snd;
      uint8_t *b21 = rb.snd.snd.fst;
      uint8_t *b11 = rb.snd.fst;
      uint8_t *b01 = rb.fst;
      memcpy(b01 + i0 * rateInBytes + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
      memcpy(b11 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
      memcpy(b21 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
      memcpy(b31 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
    }
    uint32_t rem0 = rateInBytes % 32U;
    uint32_t j = rateInBytes / 32U;
    uint8_t *b31 = rb.snd.snd.snd;
    uint8_t *b21 = rb.snd.snd.fst;
    uint8_t *b11 = rb.snd.fst;
    uint8_t *b01 = rb.fst;
    memcpy(b01 + i0 * rateInBytes + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
    memcpy(b11 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
    memcpy(b21 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
    memcpy(b31 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____34 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____35 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____36 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____34,
            Lib_IntVector_Intrinsics_vec256_xor(uu____35,
              Lib_IntVector_Intrinsics_vec256_xor(uu____36,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____37 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____38 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____37,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____38,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____38, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____39 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____39,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____39, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____40 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____41 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v023 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____40,
            Lib_IntVector_Intrinsics_vec256_and(uu____41, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____42 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____43 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v123 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____42,
            Lib_IntVector_Intrinsics_vec256_and(uu____43, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____44 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____45 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v223 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____44,
            Lib_IntVector_Intrinsics_vec256_and(uu____45, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____46 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____47 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v323 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____46,
            Lib_IntVector_Intrinsics_vec256_and(uu____47, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____48 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____49 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____48,
            Lib_IntVector_Intrinsics_vec256_and(uu____49, s[1U + 5U * i]));
        s[0U + 5U * i] = v023;
        s[1U + 5U * i] = v123;
        s[2U + 5U * i] = v223;
        s[3U + 5U * i] = v323;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____50 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____50,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t remOut = 48U % rateInBytes;
  uint8_t hbuf[1024U] = { 0U };
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
  memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
  Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
  Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
  Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
  Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256
  v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
  Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
  Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
  Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
  Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
  Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
  Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
  Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256
  v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
  Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
  Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
  Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
  Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
  Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
  Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
  Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256
  v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
  Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
  Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
  Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
  Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
  Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
  Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
  Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256
  v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
  Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
  Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
  Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
  Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
  Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
  Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
  Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256
  v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
  Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
  Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
  Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
  Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
  Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
  Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
  Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256
  v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
  Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
  Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
  Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
  Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
  Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
  Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
  Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256
  v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
  Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
  Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
  Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
  Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
  Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
  Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
  Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256
  v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
  Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
  Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
  Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
  ws[0U] = ws0;
  ws[1U] = ws1;
  ws[2U] = ws2;
  ws[3U] = ws3;
  ws[4U] = ws4;
  ws[5U] = ws5;
  ws[6U] = ws6;
  ws[7U] = ws7;
  ws[8U] = ws8;
  ws[9U] = ws9;
  ws[10U] = ws10;
  ws[11U] = ws11;
  ws[12U] = ws12;
  ws[13U] = ws13;
  ws[14U] = ws14;
  ws[15U] = ws15;
  ws[16U] = ws16;
  ws[17U] = ws17;
  ws[18U] = ws18;
  ws[19U] = ws19;
  ws[20U] = ws20;
  ws[21U] = ws21;
  ws[22U] = ws22;
  ws[23U] = ws23;
  ws[24U] = ws24;
  ws[25U] = ws25;
  ws[26U] = ws26;
  ws[27U] = ws27;
  ws[28U] = ws28;
  ws[29U] = ws29;
  ws[30U] = ws30;
  ws[31U] = ws31;
  for (uint32_t i = 0U; i < 32U; i++)
  {
    Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
  }
  for (uint32_t i = 0U; i < remOut / 32U; i++)
  {
    uint8_t *b3 = rb.snd.snd.snd;
    uint8_t *b2 = rb.snd.snd.fst;
    uint8_t *b1 = rb.snd.fst;
    uint8_t *b0 = rb.fst;
    memcpy(b0 + 48U - remOut + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
    memcpy(b1 + 48U - remOut + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
    memcpy(b2 + 48U - remOut + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
    memcpy(b3 + 48U - remOut + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
  }
  uint32_t rem0 = remOut % 32U;
  uint32_t j = remOut / 32U;
  uint8_t *b3 = rb.snd.snd.snd;
  uint8_t *b2 = rb.snd.snd.fst;
  uint8_t *b1 = rb.snd.fst;
  uint8_t *b0 = rb.fst;
  memcpy(b0 + 48U - remOut + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
  memcpy(b1 + 48U - remOut + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
  memcpy(b2 + 48U - remOut + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
  memcpy(b3 + 48U - remOut + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
}

void
Hacl_Hash_SHA3_Simd256_sha3_512(
  uint32_t inputByteLen,
  uint8_t *input0,
  uint8_t *input1,
  uint8_t *input2,
  uint8_t *input3,
  uint8_t *output0,
  uint8_t *output1,
  uint8_t *output2,
  uint8_t *output3
)
{
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  ib = { .fst = input0, .snd = { .fst = input1, .snd = { .fst = input2, .snd = input3 } } };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  rb = { .fst = output0, .snd = { .fst = output1, .snd = { .fst = output2, .snd = output3 } } };
  uint32_t rateInBytes = 72U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 s[25U] KRML_POST_ALIGN(32) = { 0U };
  for (uint32_t i0 = 0U; i0 < inputByteLen / rateInBytes; i0++)
  {
    uint8_t b00[256U] = { 0U };
    uint8_t b10[256U] = { 0U };
    uint8_t b20[256U] = { 0U };
    uint8_t b30[256U] = { 0U };
    K____uint8_t___uint8_t____K____uint8_t___uint8_t_
    b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
    uint8_t *b31 = ib.snd.snd.snd;
    uint8_t *b21 = ib.snd.snd.fst;
    uint8_t *b11 = ib.snd.fst;
    uint8_t *b01 = ib.fst;
    uint8_t *bl3 = b_.snd.snd.snd;
    uint8_t *bl2 = b_.snd.snd.fst;
    uint8_t *bl1 = b_.snd.fst;
    uint8_t *bl0 = b_.fst;
    memcpy(bl0, b01 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl1, b11 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl2, b21 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    memcpy(bl3, b31 + i0 * rateInBytes, rateInBytes * sizeof (uint8_t));
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    uint8_t *b3 = b_.snd.snd.snd;
    uint8_t *b2 = b_.snd.snd.fst;
    uint8_t *b1 = b_.snd.fst;
    uint8_t *b0 = b_.fst;
    ws[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0);
    ws[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1);
    ws[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2);
    ws[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3);
    ws[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 32U);
    ws[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 32U);
    ws[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 32U);
    ws[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 32U);
    ws[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 64U);
    ws[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 64U);
    ws[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 64U);
    ws[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 64U);
    ws[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 96U);
    ws[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 96U);
    ws[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 96U);
    ws[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 96U);
    ws[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 128U);
    ws[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 128U);
    ws[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 128U);
    ws[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 128U);
    ws[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 160U);
    ws[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 160U);
    ws[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 160U);
    ws[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 160U);
    ws[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 192U);
    ws[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 192U);
    ws[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 192U);
    ws[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 192U);
    ws[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b0 + 224U);
    ws[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b1 + 224U);
    ws[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b2 + 224U);
    ws[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b3 + 224U);
    Lib_IntVector_Intrinsics_vec256 v00 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v10 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v20 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v30 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
    Lib_IntVector_Intrinsics_vec256
    v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
    Lib_IntVector_Intrinsics_vec256
    v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
    Lib_IntVector_Intrinsics_vec256
    v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256
    v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__;
    Lib_IntVector_Intrinsics_vec256 v01 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v11 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v21 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v31 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
    Lib_IntVector_Intrinsics_vec256
    v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
    Lib_IntVector_Intrinsics_vec256
    v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
    Lib_IntVector_Intrinsics_vec256
    v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256
    v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__0;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__0;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__0;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__0;
    Lib_IntVector_Intrinsics_vec256 v02 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v12 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v22 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v32 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
    Lib_IntVector_Intrinsics_vec256
    v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
    Lib_IntVector_Intrinsics_vec256
    v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
    Lib_IntVector_Intrinsics_vec256
    v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256
    v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__1;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__1;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__1;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__1;
    Lib_IntVector_Intrinsics_vec256 v03 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v13 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v23 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v33 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
    Lib_IntVector_Intrinsics_vec256
    v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
    Lib_IntVector_Intrinsics_vec256
    v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
    Lib_IntVector_Intrinsics_vec256
    v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256
    v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__2;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__2;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__2;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__2;
    Lib_IntVector_Intrinsics_vec256 v04 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v14 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v24 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v34 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
    Lib_IntVector_Intrinsics_vec256
    v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
    Lib_IntVector_Intrinsics_vec256
    v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
    Lib_IntVector_Intrinsics_vec256
    v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256
    v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__3;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__3;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__3;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__3;
    Lib_IntVector_Intrinsics_vec256 v05 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v15 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v25 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v35 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
    Lib_IntVector_Intrinsics_vec256
    v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
    Lib_IntVector_Intrinsics_vec256
    v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
    Lib_IntVector_Intrinsics_vec256
    v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256
    v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__4;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__4;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__4;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__4;
    Lib_IntVector_Intrinsics_vec256 v06 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v16 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v26 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v36 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
    Lib_IntVector_Intrinsics_vec256
    v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
    Lib_IntVector_Intrinsics_vec256
    v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
    Lib_IntVector_Intrinsics_vec256
    v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256
    v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__5;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__5;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__5;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__5;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
    Lib_IntVector_Intrinsics_vec256
    v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256
    v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__6;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__6;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__6;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__6;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 25U; i++)
    {
      s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws[i]);
    }
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____0 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____1 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____2 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____0,
            Lib_IntVector_Intrinsics_vec256_xor(uu____1,
              Lib_IntVector_Intrinsics_vec256_xor(uu____2,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____3 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____4 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____3,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____4,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____4, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____5 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____5,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____5, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____6 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____7 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v07 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____6,
            Lib_IntVector_Intrinsics_vec256_and(uu____7, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____8 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____9 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v17 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____8,
            Lib_IntVector_Intrinsics_vec256_and(uu____9, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____10 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____11 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v27 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____10,
            Lib_IntVector_Intrinsics_vec256_and(uu____11, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____12 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____13 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v37 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____12,
            Lib_IntVector_Intrinsics_vec256_and(uu____13, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____14 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____15 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____14,
            Lib_IntVector_Intrinsics_vec256_and(uu____15, s[1U + 5U * i]));
        s[0U + 5U * i] = v07;
        s[1U + 5U * i] = v17;
        s[2U + 5U * i] = v27;
        s[3U + 5U * i] = v37;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____16 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____16,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t rem = inputByteLen % rateInBytes;
  uint8_t b00[256U] = { 0U };
  uint8_t b10[256U] = { 0U };
  uint8_t b20[256U] = { 0U };
  uint8_t b30[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b_ = { .fst = b00, .snd = { .fst = b10, .snd = { .fst = b20, .snd = b30 } } };
  uint32_t rem1 = inputByteLen % rateInBytes;
  uint8_t *b32 = ib.snd.snd.snd;
  uint8_t *b22 = ib.snd.snd.fst;
  uint8_t *b12 = ib.snd.fst;
  uint8_t *b02 = ib.fst;
  uint8_t *bl3 = b_.snd.snd.snd;
  uint8_t *bl2 = b_.snd.snd.fst;
  uint8_t *bl1 = b_.snd.fst;
  uint8_t *bl0 = b_.fst;
  memcpy(bl0, b02 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl1, b12 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl2, b22 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  memcpy(bl3, b32 + inputByteLen - rem1, rem1 * sizeof (uint8_t));
  uint8_t *b33 = b_.snd.snd.snd;
  uint8_t *b23 = b_.snd.snd.fst;
  uint8_t *b13 = b_.snd.fst;
  uint8_t *b03 = b_.fst;
  b03[rem] = 0x06U;
  b13[rem] = 0x06U;
  b23[rem] = 0x06U;
  b33[rem] = 0x06U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws32[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b34 = b_.snd.snd.snd;
  uint8_t *b24 = b_.snd.snd.fst;
  uint8_t *b14 = b_.snd.fst;
  uint8_t *b04 = b_.fst;
  ws32[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04);
  ws32[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14);
  ws32[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24);
  ws32[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34);
  ws32[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 32U);
  ws32[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 32U);
  ws32[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 32U);
  ws32[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 32U);
  ws32[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 64U);
  ws32[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 64U);
  ws32[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 64U);
  ws32[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 64U);
  ws32[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 96U);
  ws32[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 96U);
  ws32[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 96U);
  ws32[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 96U);
  ws32[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 128U);
  ws32[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 128U);
  ws32[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 128U);
  ws32[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 128U);
  ws32[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 160U);
  ws32[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 160U);
  ws32[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 160U);
  ws32[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 160U);
  ws32[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 192U);
  ws32[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 192U);
  ws32[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 192U);
  ws32[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 192U);
  ws32[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b04 + 224U);
  ws32[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b14 + 224U);
  ws32[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b24 + 224U);
  ws32[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b34 + 224U);
  Lib_IntVector_Intrinsics_vec256 v00 = ws32[0U];
  Lib_IntVector_Intrinsics_vec256 v10 = ws32[1U];
  Lib_IntVector_Intrinsics_vec256 v20 = ws32[2U];
  Lib_IntVector_Intrinsics_vec256 v30 = ws32[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v1_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v00, v10);
  Lib_IntVector_Intrinsics_vec256
  v2_ = Lib_IntVector_Intrinsics_vec256_interleave_low64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v3_ = Lib_IntVector_Intrinsics_vec256_interleave_high64(v20, v30);
  Lib_IntVector_Intrinsics_vec256
  v0__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v1__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_, v2_);
  Lib_IntVector_Intrinsics_vec256
  v2__ = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256
  v3__ = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_, v3_);
  Lib_IntVector_Intrinsics_vec256 ws00 = v0__;
  Lib_IntVector_Intrinsics_vec256 ws110 = v2__;
  Lib_IntVector_Intrinsics_vec256 ws210 = v1__;
  Lib_IntVector_Intrinsics_vec256 ws33 = v3__;
  Lib_IntVector_Intrinsics_vec256 v01 = ws32[4U];
  Lib_IntVector_Intrinsics_vec256 v11 = ws32[5U];
  Lib_IntVector_Intrinsics_vec256 v21 = ws32[6U];
  Lib_IntVector_Intrinsics_vec256 v31 = ws32[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v1_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v01, v11);
  Lib_IntVector_Intrinsics_vec256
  v2_0 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v3_0 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v21, v31);
  Lib_IntVector_Intrinsics_vec256
  v0__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v1__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_0, v2_0);
  Lib_IntVector_Intrinsics_vec256
  v2__0 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256
  v3__0 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_0, v3_0);
  Lib_IntVector_Intrinsics_vec256 ws40 = v0__0;
  Lib_IntVector_Intrinsics_vec256 ws50 = v2__0;
  Lib_IntVector_Intrinsics_vec256 ws60 = v1__0;
  Lib_IntVector_Intrinsics_vec256 ws70 = v3__0;
  Lib_IntVector_Intrinsics_vec256 v02 = ws32[8U];
  Lib_IntVector_Intrinsics_vec256 v12 = ws32[9U];
  Lib_IntVector_Intrinsics_vec256 v22 = ws32[10U];
  Lib_IntVector_Intrinsics_vec256 v32 = ws32[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v1_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v02, v12);
  Lib_IntVector_Intrinsics_vec256
  v2_1 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v3_1 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v22, v32);
  Lib_IntVector_Intrinsics_vec256
  v0__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v1__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_1, v2_1);
  Lib_IntVector_Intrinsics_vec256
  v2__1 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256
  v3__1 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_1, v3_1);
  Lib_IntVector_Intrinsics_vec256 ws80 = v0__1;
  Lib_IntVector_Intrinsics_vec256 ws90 = v2__1;
  Lib_IntVector_Intrinsics_vec256 ws100 = v1__1;
  Lib_IntVector_Intrinsics_vec256 ws111 = v3__1;
  Lib_IntVector_Intrinsics_vec256 v03 = ws32[12U];
  Lib_IntVector_Intrinsics_vec256 v13 = ws32[13U];
  Lib_IntVector_Intrinsics_vec256 v23 = ws32[14U];
  Lib_IntVector_Intrinsics_vec256 v33 = ws32[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v1_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v03, v13);
  Lib_IntVector_Intrinsics_vec256
  v2_2 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v3_2 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v23, v33);
  Lib_IntVector_Intrinsics_vec256
  v0__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v1__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_2, v2_2);
  Lib_IntVector_Intrinsics_vec256
  v2__2 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256
  v3__2 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_2, v3_2);
  Lib_IntVector_Intrinsics_vec256 ws120 = v0__2;
  Lib_IntVector_Intrinsics_vec256 ws130 = v2__2;
  Lib_IntVector_Intrinsics_vec256 ws140 = v1__2;
  Lib_IntVector_Intrinsics_vec256 ws150 = v3__2;
  Lib_IntVector_Intrinsics_vec256 v04 = ws32[16U];
  Lib_IntVector_Intrinsics_vec256 v14 = ws32[17U];
  Lib_IntVector_Intrinsics_vec256 v24 = ws32[18U];
  Lib_IntVector_Intrinsics_vec256 v34 = ws32[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v1_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v04, v14);
  Lib_IntVector_Intrinsics_vec256
  v2_3 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v3_3 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v24, v34);
  Lib_IntVector_Intrinsics_vec256
  v0__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v1__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_3, v2_3);
  Lib_IntVector_Intrinsics_vec256
  v2__3 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256
  v3__3 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_3, v3_3);
  Lib_IntVector_Intrinsics_vec256 ws160 = v0__3;
  Lib_IntVector_Intrinsics_vec256 ws170 = v2__3;
  Lib_IntVector_Intrinsics_vec256 ws180 = v1__3;
  Lib_IntVector_Intrinsics_vec256 ws190 = v3__3;
  Lib_IntVector_Intrinsics_vec256 v05 = ws32[20U];
  Lib_IntVector_Intrinsics_vec256 v15 = ws32[21U];
  Lib_IntVector_Intrinsics_vec256 v25 = ws32[22U];
  Lib_IntVector_Intrinsics_vec256 v35 = ws32[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v1_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v05, v15);
  Lib_IntVector_Intrinsics_vec256
  v2_4 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v3_4 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v25, v35);
  Lib_IntVector_Intrinsics_vec256
  v0__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v1__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_4, v2_4);
  Lib_IntVector_Intrinsics_vec256
  v2__4 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256
  v3__4 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_4, v3_4);
  Lib_IntVector_Intrinsics_vec256 ws200 = v0__4;
  Lib_IntVector_Intrinsics_vec256 ws211 = v2__4;
  Lib_IntVector_Intrinsics_vec256 ws220 = v1__4;
  Lib_IntVector_Intrinsics_vec256 ws230 = v3__4;
  Lib_IntVector_Intrinsics_vec256 v06 = ws32[24U];
  Lib_IntVector_Intrinsics_vec256 v16 = ws32[25U];
  Lib_IntVector_Intrinsics_vec256 v26 = ws32[26U];
  Lib_IntVector_Intrinsics_vec256 v36 = ws32[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v1_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v06, v16);
  Lib_IntVector_Intrinsics_vec256
  v2_5 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v3_5 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v26, v36);
  Lib_IntVector_Intrinsics_vec256
  v0__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v1__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_5, v2_5);
  Lib_IntVector_Intrinsics_vec256
  v2__5 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256
  v3__5 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_5, v3_5);
  Lib_IntVector_Intrinsics_vec256 ws240 = v0__5;
  Lib_IntVector_Intrinsics_vec256 ws250 = v2__5;
  Lib_IntVector_Intrinsics_vec256 ws260 = v1__5;
  Lib_IntVector_Intrinsics_vec256 ws270 = v3__5;
  Lib_IntVector_Intrinsics_vec256 v07 = ws32[28U];
  Lib_IntVector_Intrinsics_vec256 v17 = ws32[29U];
  Lib_IntVector_Intrinsics_vec256 v27 = ws32[30U];
  Lib_IntVector_Intrinsics_vec256 v37 = ws32[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v1_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v07, v17);
  Lib_IntVector_Intrinsics_vec256
  v2_6 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v3_6 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v27, v37);
  Lib_IntVector_Intrinsics_vec256
  v0__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v1__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_6, v2_6);
  Lib_IntVector_Intrinsics_vec256
  v2__6 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256
  v3__6 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_6, v3_6);
  Lib_IntVector_Intrinsics_vec256 ws280 = v0__6;
  Lib_IntVector_Intrinsics_vec256 ws290 = v2__6;
  Lib_IntVector_Intrinsics_vec256 ws300 = v1__6;
  Lib_IntVector_Intrinsics_vec256 ws310 = v3__6;
  ws32[0U] = ws00;
  ws32[1U] = ws110;
  ws32[2U] = ws210;
  ws32[3U] = ws33;
  ws32[4U] = ws40;
  ws32[5U] = ws50;
  ws32[6U] = ws60;
  ws32[7U] = ws70;
  ws32[8U] = ws80;
  ws32[9U] = ws90;
  ws32[10U] = ws100;
  ws32[11U] = ws111;
  ws32[12U] = ws120;
  ws32[13U] = ws130;
  ws32[14U] = ws140;
  ws32[15U] = ws150;
  ws32[16U] = ws160;
  ws32[17U] = ws170;
  ws32[18U] = ws180;
  ws32[19U] = ws190;
  ws32[20U] = ws200;
  ws32[21U] = ws211;
  ws32[22U] = ws220;
  ws32[23U] = ws230;
  ws32[24U] = ws240;
  ws32[25U] = ws250;
  ws32[26U] = ws260;
  ws32[27U] = ws270;
  ws32[28U] = ws280;
  ws32[29U] = ws290;
  ws32[30U] = ws300;
  ws32[31U] = ws310;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws32[i]);
  }
  uint8_t b05[256U] = { 0U };
  uint8_t b15[256U] = { 0U };
  uint8_t b25[256U] = { 0U };
  uint8_t b35[256U] = { 0U };
  K____uint8_t___uint8_t____K____uint8_t___uint8_t_
  b = { .fst = b05, .snd = { .fst = b15, .snd = { .fst = b25, .snd = b35 } } };
  uint8_t *b36 = b.snd.snd.snd;
  uint8_t *b26 = b.snd.snd.fst;
  uint8_t *b16 = b.snd.fst;
  uint8_t *b06 = b.fst;
  b06[rateInBytes - 1U] = 0x80U;
  b16[rateInBytes - 1U] = 0x80U;
  b26[rateInBytes - 1U] = 0x80U;
  b36[rateInBytes - 1U] = 0x80U;
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws34[32U] KRML_POST_ALIGN(32) = { 0U };
  uint8_t *b37 = b.snd.snd.snd;
  uint8_t *b27 = b.snd.snd.fst;
  uint8_t *b17 = b.snd.fst;
  uint8_t *b07 = b.fst;
  ws34[0U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07);
  ws34[1U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17);
  ws34[2U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27);
  ws34[3U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37);
  ws34[4U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 32U);
  ws34[5U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 32U);
  ws34[6U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 32U);
  ws34[7U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 32U);
  ws34[8U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 64U);
  ws34[9U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 64U);
  ws34[10U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 64U);
  ws34[11U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 64U);
  ws34[12U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 96U);
  ws34[13U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 96U);
  ws34[14U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 96U);
  ws34[15U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 96U);
  ws34[16U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 128U);
  ws34[17U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 128U);
  ws34[18U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 128U);
  ws34[19U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 128U);
  ws34[20U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 160U);
  ws34[21U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 160U);
  ws34[22U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 160U);
  ws34[23U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 160U);
  ws34[24U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 192U);
  ws34[25U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 192U);
  ws34[26U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 192U);
  ws34[27U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 192U);
  ws34[28U] = Lib_IntVector_Intrinsics_vec256_load64_le(b07 + 224U);
  ws34[29U] = Lib_IntVector_Intrinsics_vec256_load64_le(b17 + 224U);
  ws34[30U] = Lib_IntVector_Intrinsics_vec256_load64_le(b27 + 224U);
  ws34[31U] = Lib_IntVector_Intrinsics_vec256_load64_le(b37 + 224U);
  Lib_IntVector_Intrinsics_vec256 v08 = ws34[0U];
  Lib_IntVector_Intrinsics_vec256 v18 = ws34[1U];
  Lib_IntVector_Intrinsics_vec256 v28 = ws34[2U];
  Lib_IntVector_Intrinsics_vec256 v38 = ws34[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v1_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v08, v18);
  Lib_IntVector_Intrinsics_vec256
  v2_7 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v3_7 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v28, v38);
  Lib_IntVector_Intrinsics_vec256
  v0__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v1__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_7, v2_7);
  Lib_IntVector_Intrinsics_vec256
  v2__7 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256
  v3__7 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_7, v3_7);
  Lib_IntVector_Intrinsics_vec256 ws01 = v0__7;
  Lib_IntVector_Intrinsics_vec256 ws112 = v2__7;
  Lib_IntVector_Intrinsics_vec256 ws212 = v1__7;
  Lib_IntVector_Intrinsics_vec256 ws35 = v3__7;
  Lib_IntVector_Intrinsics_vec256 v09 = ws34[4U];
  Lib_IntVector_Intrinsics_vec256 v19 = ws34[5U];
  Lib_IntVector_Intrinsics_vec256 v29 = ws34[6U];
  Lib_IntVector_Intrinsics_vec256 v39 = ws34[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v1_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v09, v19);
  Lib_IntVector_Intrinsics_vec256
  v2_8 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v3_8 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v29, v39);
  Lib_IntVector_Intrinsics_vec256
  v0__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v1__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_8, v2_8);
  Lib_IntVector_Intrinsics_vec256
  v2__8 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256
  v3__8 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_8, v3_8);
  Lib_IntVector_Intrinsics_vec256 ws41 = v0__8;
  Lib_IntVector_Intrinsics_vec256 ws51 = v2__8;
  Lib_IntVector_Intrinsics_vec256 ws61 = v1__8;
  Lib_IntVector_Intrinsics_vec256 ws71 = v3__8;
  Lib_IntVector_Intrinsics_vec256 v010 = ws34[8U];
  Lib_IntVector_Intrinsics_vec256 v110 = ws34[9U];
  Lib_IntVector_Intrinsics_vec256 v210 = ws34[10U];
  Lib_IntVector_Intrinsics_vec256 v310 = ws34[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v1_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v010, v110);
  Lib_IntVector_Intrinsics_vec256
  v2_9 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v3_9 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v210, v310);
  Lib_IntVector_Intrinsics_vec256
  v0__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v1__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_9, v2_9);
  Lib_IntVector_Intrinsics_vec256
  v2__9 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256
  v3__9 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_9, v3_9);
  Lib_IntVector_Intrinsics_vec256 ws81 = v0__9;
  Lib_IntVector_Intrinsics_vec256 ws91 = v2__9;
  Lib_IntVector_Intrinsics_vec256 ws101 = v1__9;
  Lib_IntVector_Intrinsics_vec256 ws113 = v3__9;
  Lib_IntVector_Intrinsics_vec256 v011 = ws34[12U];
  Lib_IntVector_Intrinsics_vec256 v111 = ws34[13U];
  Lib_IntVector_Intrinsics_vec256 v211 = ws34[14U];
  Lib_IntVector_Intrinsics_vec256 v311 = ws34[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v1_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v011, v111);
  Lib_IntVector_Intrinsics_vec256
  v2_10 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v3_10 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v211, v311);
  Lib_IntVector_Intrinsics_vec256
  v0__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v1__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_10, v2_10);
  Lib_IntVector_Intrinsics_vec256
  v2__10 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256
  v3__10 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_10, v3_10);
  Lib_IntVector_Intrinsics_vec256 ws121 = v0__10;
  Lib_IntVector_Intrinsics_vec256 ws131 = v2__10;
  Lib_IntVector_Intrinsics_vec256 ws141 = v1__10;
  Lib_IntVector_Intrinsics_vec256 ws151 = v3__10;
  Lib_IntVector_Intrinsics_vec256 v012 = ws34[16U];
  Lib_IntVector_Intrinsics_vec256 v112 = ws34[17U];
  Lib_IntVector_Intrinsics_vec256 v212 = ws34[18U];
  Lib_IntVector_Intrinsics_vec256 v312 = ws34[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v1_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v012, v112);
  Lib_IntVector_Intrinsics_vec256
  v2_11 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v3_11 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v212, v312);
  Lib_IntVector_Intrinsics_vec256
  v0__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v1__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_11, v2_11);
  Lib_IntVector_Intrinsics_vec256
  v2__11 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256
  v3__11 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_11, v3_11);
  Lib_IntVector_Intrinsics_vec256 ws161 = v0__11;
  Lib_IntVector_Intrinsics_vec256 ws171 = v2__11;
  Lib_IntVector_Intrinsics_vec256 ws181 = v1__11;
  Lib_IntVector_Intrinsics_vec256 ws191 = v3__11;
  Lib_IntVector_Intrinsics_vec256 v013 = ws34[20U];
  Lib_IntVector_Intrinsics_vec256 v113 = ws34[21U];
  Lib_IntVector_Intrinsics_vec256 v213 = ws34[22U];
  Lib_IntVector_Intrinsics_vec256 v313 = ws34[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v1_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v013, v113);
  Lib_IntVector_Intrinsics_vec256
  v2_12 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v3_12 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v213, v313);
  Lib_IntVector_Intrinsics_vec256
  v0__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v1__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_12, v2_12);
  Lib_IntVector_Intrinsics_vec256
  v2__12 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256
  v3__12 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_12, v3_12);
  Lib_IntVector_Intrinsics_vec256 ws201 = v0__12;
  Lib_IntVector_Intrinsics_vec256 ws213 = v2__12;
  Lib_IntVector_Intrinsics_vec256 ws221 = v1__12;
  Lib_IntVector_Intrinsics_vec256 ws231 = v3__12;
  Lib_IntVector_Intrinsics_vec256 v014 = ws34[24U];
  Lib_IntVector_Intrinsics_vec256 v114 = ws34[25U];
  Lib_IntVector_Intrinsics_vec256 v214 = ws34[26U];
  Lib_IntVector_Intrinsics_vec256 v314 = ws34[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v1_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v014, v114);
  Lib_IntVector_Intrinsics_vec256
  v2_13 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v3_13 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v214, v314);
  Lib_IntVector_Intrinsics_vec256
  v0__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v1__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_13, v2_13);
  Lib_IntVector_Intrinsics_vec256
  v2__13 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256
  v3__13 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_13, v3_13);
  Lib_IntVector_Intrinsics_vec256 ws241 = v0__13;
  Lib_IntVector_Intrinsics_vec256 ws251 = v2__13;
  Lib_IntVector_Intrinsics_vec256 ws261 = v1__13;
  Lib_IntVector_Intrinsics_vec256 ws271 = v3__13;
  Lib_IntVector_Intrinsics_vec256 v015 = ws34[28U];
  Lib_IntVector_Intrinsics_vec256 v115 = ws34[29U];
  Lib_IntVector_Intrinsics_vec256 v215 = ws34[30U];
  Lib_IntVector_Intrinsics_vec256 v315 = ws34[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v1_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v015, v115);
  Lib_IntVector_Intrinsics_vec256
  v2_14 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v3_14 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v215, v315);
  Lib_IntVector_Intrinsics_vec256
  v0__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v1__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_14, v2_14);
  Lib_IntVector_Intrinsics_vec256
  v2__14 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256
  v3__14 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_14, v3_14);
  Lib_IntVector_Intrinsics_vec256 ws281 = v0__14;
  Lib_IntVector_Intrinsics_vec256 ws291 = v2__14;
  Lib_IntVector_Intrinsics_vec256 ws301 = v1__14;
  Lib_IntVector_Intrinsics_vec256 ws311 = v3__14;
  ws34[0U] = ws01;
  ws34[1U] = ws112;
  ws34[2U] = ws212;
  ws34[3U] = ws35;
  ws34[4U] = ws41;
  ws34[5U] = ws51;
  ws34[6U] = ws61;
  ws34[7U] = ws71;
  ws34[8U] = ws81;
  ws34[9U] = ws91;
  ws34[10U] = ws101;
  ws34[11U] = ws113;
  ws34[12U] = ws121;
  ws34[13U] = ws131;
  ws34[14U] = ws141;
  ws34[15U] = ws151;
  ws34[16U] = ws161;
  ws34[17U] = ws171;
  ws34[18U] = ws181;
  ws34[19U] = ws191;
  ws34[20U] = ws201;
  ws34[21U] = ws213;
  ws34[22U] = ws221;
  ws34[23U] = ws231;
  ws34[24U] = ws241;
  ws34[25U] = ws251;
  ws34[26U] = ws261;
  ws34[27U] = ws271;
  ws34[28U] = ws281;
  ws34[29U] = ws291;
  ws34[30U] = ws301;
  ws34[31U] = ws311;
  for (uint32_t i = 0U; i < 25U; i++)
  {
    s[i] = Lib_IntVector_Intrinsics_vec256_xor(s[i], ws34[i]);
  }
  for (uint32_t i0 = 0U; i0 < 24U; i0++)
  {
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____17 = s[i + 0U];
      Lib_IntVector_Intrinsics_vec256 uu____18 = s[i + 5U];
      Lib_IntVector_Intrinsics_vec256 uu____19 = s[i + 10U];
      _C[i] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____17,
          Lib_IntVector_Intrinsics_vec256_xor(uu____18,
            Lib_IntVector_Intrinsics_vec256_xor(uu____19,
              Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
    KRML_MAYBE_FOR5(i1,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____20 = _C[(i1 + 4U) % 5U];
      Lib_IntVector_Intrinsics_vec256 uu____21 = _C[(i1 + 1U) % 5U];
      Lib_IntVector_Intrinsics_vec256
      _D =
        Lib_IntVector_Intrinsics_vec256_xor(uu____20,
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____21,
              1U),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____21, 63U)));
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        s[i1 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i1 + 5U * i], _D);););
    Lib_IntVector_Intrinsics_vec256 x = s[1U];
    Lib_IntVector_Intrinsics_vec256 current = x;
    for (uint32_t i = 0U; i < 24U; i++)
    {
      uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
      uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
      Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
      Lib_IntVector_Intrinsics_vec256 uu____22 = current;
      s[_Y] =
        Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____22, r),
          Lib_IntVector_Intrinsics_vec256_shift_right64(uu____22, 64U - r));
      current = temp;
    }
    KRML_MAYBE_FOR5(i,
      0U,
      5U,
      1U,
      Lib_IntVector_Intrinsics_vec256 uu____23 = s[0U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____24 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v0 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____23,
          Lib_IntVector_Intrinsics_vec256_and(uu____24, s[2U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____25 = s[1U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____26 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v1 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____25,
          Lib_IntVector_Intrinsics_vec256_and(uu____26, s[3U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____27 = s[2U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____28 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v2 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____27,
          Lib_IntVector_Intrinsics_vec256_and(uu____28, s[4U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____29 = s[3U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____30 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v3 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____29,
          Lib_IntVector_Intrinsics_vec256_and(uu____30, s[0U + 5U * i]));
      Lib_IntVector_Intrinsics_vec256 uu____31 = s[4U + 5U * i];
      Lib_IntVector_Intrinsics_vec256
      uu____32 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
      Lib_IntVector_Intrinsics_vec256
      v4 =
        Lib_IntVector_Intrinsics_vec256_xor(uu____31,
          Lib_IntVector_Intrinsics_vec256_and(uu____32, s[1U + 5U * i]));
      s[0U + 5U * i] = v0;
      s[1U + 5U * i] = v1;
      s[2U + 5U * i] = v2;
      s[3U + 5U * i] = v3;
      s[4U + 5U * i] = v4;);
    uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i0];
    Lib_IntVector_Intrinsics_vec256 uu____33 = s[0U];
    s[0U] =
      Lib_IntVector_Intrinsics_vec256_xor(uu____33,
        Lib_IntVector_Intrinsics_vec256_load64(c));
  }
  for (uint32_t i0 = 0U; i0 < 64U / rateInBytes; i0++)
  {
    uint8_t hbuf[1024U] = { 0U };
    KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
    memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
    Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
    Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
    Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
    Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
    Lib_IntVector_Intrinsics_vec256
    v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
    Lib_IntVector_Intrinsics_vec256
    v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
    Lib_IntVector_Intrinsics_vec256
    v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
    Lib_IntVector_Intrinsics_vec256
    v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256
    v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
    Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
    Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
    Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
    Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
    Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
    Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
    Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
    Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
    Lib_IntVector_Intrinsics_vec256
    v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
    Lib_IntVector_Intrinsics_vec256
    v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
    Lib_IntVector_Intrinsics_vec256
    v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
    Lib_IntVector_Intrinsics_vec256
    v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256
    v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
    Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
    Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
    Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
    Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
    Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
    Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
    Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
    Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
    Lib_IntVector_Intrinsics_vec256
    v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
    Lib_IntVector_Intrinsics_vec256
    v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
    Lib_IntVector_Intrinsics_vec256
    v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
    Lib_IntVector_Intrinsics_vec256
    v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256
    v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
    Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
    Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
    Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
    Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
    Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
    Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
    Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
    Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
    Lib_IntVector_Intrinsics_vec256
    v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
    Lib_IntVector_Intrinsics_vec256
    v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
    Lib_IntVector_Intrinsics_vec256
    v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
    Lib_IntVector_Intrinsics_vec256
    v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256
    v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
    Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
    Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
    Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
    Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
    Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
    Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
    Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
    Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
    Lib_IntVector_Intrinsics_vec256
    v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
    Lib_IntVector_Intrinsics_vec256
    v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
    Lib_IntVector_Intrinsics_vec256
    v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
    Lib_IntVector_Intrinsics_vec256
    v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256
    v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
    Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
    Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
    Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
    Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
    Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
    Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
    Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
    Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
    Lib_IntVector_Intrinsics_vec256
    v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
    Lib_IntVector_Intrinsics_vec256
    v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
    Lib_IntVector_Intrinsics_vec256
    v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
    Lib_IntVector_Intrinsics_vec256
    v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256
    v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
    Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
    Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
    Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
    Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
    Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
    Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
    Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
    Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
    Lib_IntVector_Intrinsics_vec256
    v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
    Lib_IntVector_Intrinsics_vec256
    v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
    Lib_IntVector_Intrinsics_vec256
    v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
    Lib_IntVector_Intrinsics_vec256
    v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256
    v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
    Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
    Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
    Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
    Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
    Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
    Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
    Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
    Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
    Lib_IntVector_Intrinsics_vec256
    v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
    Lib_IntVector_Intrinsics_vec256
    v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
    Lib_IntVector_Intrinsics_vec256
    v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
    Lib_IntVector_Intrinsics_vec256
    v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256
    v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
    Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
    Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
    Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
    Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
    ws[0U] = ws0;
    ws[1U] = ws1;
    ws[2U] = ws2;
    ws[3U] = ws3;
    ws[4U] = ws4;
    ws[5U] = ws5;
    ws[6U] = ws6;
    ws[7U] = ws7;
    ws[8U] = ws8;
    ws[9U] = ws9;
    ws[10U] = ws10;
    ws[11U] = ws11;
    ws[12U] = ws12;
    ws[13U] = ws13;
    ws[14U] = ws14;
    ws[15U] = ws15;
    ws[16U] = ws16;
    ws[17U] = ws17;
    ws[18U] = ws18;
    ws[19U] = ws19;
    ws[20U] = ws20;
    ws[21U] = ws21;
    ws[22U] = ws22;
    ws[23U] = ws23;
    ws[24U] = ws24;
    ws[25U] = ws25;
    ws[26U] = ws26;
    ws[27U] = ws27;
    ws[28U] = ws28;
    ws[29U] = ws29;
    ws[30U] = ws30;
    ws[31U] = ws31;
    for (uint32_t i = 0U; i < 32U; i++)
    {
      Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
    }
    for (uint32_t i = 0U; i < rateInBytes / 32U; i++)
    {
      uint8_t *b31 = rb.snd.snd.snd;
      uint8_t *b21 = rb.snd.snd.fst;
      uint8_t *b11 = rb.snd.fst;
      uint8_t *b01 = rb.fst;
      memcpy(b01 + i0 * rateInBytes + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
      memcpy(b11 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
      memcpy(b21 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
      memcpy(b31 + i0 * rateInBytes + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
    }
    uint32_t rem0 = rateInBytes % 32U;
    uint32_t j = rateInBytes / 32U;
    uint8_t *b31 = rb.snd.snd.snd;
    uint8_t *b21 = rb.snd.snd.fst;
    uint8_t *b11 = rb.snd.fst;
    uint8_t *b01 = rb.fst;
    memcpy(b01 + i0 * rateInBytes + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
    memcpy(b11 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
    memcpy(b21 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
    memcpy(b31 + i0 * rateInBytes + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
    for (uint32_t i1 = 0U; i1 < 24U; i1++)
    {
      KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 _C[5U] KRML_POST_ALIGN(32) = { 0U };
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____34 = s[i + 0U];
        Lib_IntVector_Intrinsics_vec256 uu____35 = s[i + 5U];
        Lib_IntVector_Intrinsics_vec256 uu____36 = s[i + 10U];
        _C[i] =
          Lib_IntVector_Intrinsics_vec256_xor(uu____34,
            Lib_IntVector_Intrinsics_vec256_xor(uu____35,
              Lib_IntVector_Intrinsics_vec256_xor(uu____36,
                Lib_IntVector_Intrinsics_vec256_xor(s[i + 15U], s[i + 20U])))););
      KRML_MAYBE_FOR5(i2,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____37 = _C[(i2 + 4U) % 5U];
        Lib_IntVector_Intrinsics_vec256 uu____38 = _C[(i2 + 1U) % 5U];
        Lib_IntVector_Intrinsics_vec256
        _D =
          Lib_IntVector_Intrinsics_vec256_xor(uu____37,
            Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____38,
                1U),
              Lib_IntVector_Intrinsics_vec256_shift_right64(uu____38, 63U)));
        KRML_MAYBE_FOR5(i,
          0U,
          5U,
          1U,
          s[i2 + 5U * i] = Lib_IntVector_Intrinsics_vec256_xor(s[i2 + 5U * i], _D);););
      Lib_IntVector_Intrinsics_vec256 x = s[1U];
      Lib_IntVector_Intrinsics_vec256 current = x;
      for (uint32_t i = 0U; i < 24U; i++)
      {
        uint32_t _Y = Hacl_Impl_SHA3_Vec_keccak_piln[i];
        uint32_t r = Hacl_Impl_SHA3_Vec_keccak_rotc[i];
        Lib_IntVector_Intrinsics_vec256 temp = s[_Y];
        Lib_IntVector_Intrinsics_vec256 uu____39 = current;
        s[_Y] =
          Lib_IntVector_Intrinsics_vec256_or(Lib_IntVector_Intrinsics_vec256_shift_left64(uu____39,
              r),
            Lib_IntVector_Intrinsics_vec256_shift_right64(uu____39, 64U - r));
        current = temp;
      }
      KRML_MAYBE_FOR5(i,
        0U,
        5U,
        1U,
        Lib_IntVector_Intrinsics_vec256 uu____40 = s[0U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____41 = Lib_IntVector_Intrinsics_vec256_lognot(s[1U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v023 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____40,
            Lib_IntVector_Intrinsics_vec256_and(uu____41, s[2U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____42 = s[1U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____43 = Lib_IntVector_Intrinsics_vec256_lognot(s[2U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v123 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____42,
            Lib_IntVector_Intrinsics_vec256_and(uu____43, s[3U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____44 = s[2U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____45 = Lib_IntVector_Intrinsics_vec256_lognot(s[3U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v223 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____44,
            Lib_IntVector_Intrinsics_vec256_and(uu____45, s[4U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____46 = s[3U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____47 = Lib_IntVector_Intrinsics_vec256_lognot(s[4U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v323 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____46,
            Lib_IntVector_Intrinsics_vec256_and(uu____47, s[0U + 5U * i]));
        Lib_IntVector_Intrinsics_vec256 uu____48 = s[4U + 5U * i];
        Lib_IntVector_Intrinsics_vec256
        uu____49 = Lib_IntVector_Intrinsics_vec256_lognot(s[0U + 5U * i]);
        Lib_IntVector_Intrinsics_vec256
        v4 =
          Lib_IntVector_Intrinsics_vec256_xor(uu____48,
            Lib_IntVector_Intrinsics_vec256_and(uu____49, s[1U + 5U * i]));
        s[0U + 5U * i] = v023;
        s[1U + 5U * i] = v123;
        s[2U + 5U * i] = v223;
        s[3U + 5U * i] = v323;
        s[4U + 5U * i] = v4;);
      uint64_t c = Hacl_Impl_SHA3_Vec_keccak_rndc[i1];
      Lib_IntVector_Intrinsics_vec256 uu____50 = s[0U];
      s[0U] =
        Lib_IntVector_Intrinsics_vec256_xor(uu____50,
          Lib_IntVector_Intrinsics_vec256_load64(c));
    }
  }
  uint32_t remOut = 64U % rateInBytes;
  uint8_t hbuf[1024U] = { 0U };
  KRML_PRE_ALIGN(32) Lib_IntVector_Intrinsics_vec256 ws[32U] KRML_POST_ALIGN(32) = { 0U };
  memcpy(ws, s, 25U * sizeof (Lib_IntVector_Intrinsics_vec256));
  Lib_IntVector_Intrinsics_vec256 v016 = ws[0U];
  Lib_IntVector_Intrinsics_vec256 v116 = ws[1U];
  Lib_IntVector_Intrinsics_vec256 v216 = ws[2U];
  Lib_IntVector_Intrinsics_vec256 v316 = ws[3U];
  Lib_IntVector_Intrinsics_vec256
  v0_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v1_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v016, v116);
  Lib_IntVector_Intrinsics_vec256
  v2_15 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v3_15 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v216, v316);
  Lib_IntVector_Intrinsics_vec256
  v0__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v1__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_15, v2_15);
  Lib_IntVector_Intrinsics_vec256
  v2__15 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256
  v3__15 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_15, v3_15);
  Lib_IntVector_Intrinsics_vec256 ws0 = v0__15;
  Lib_IntVector_Intrinsics_vec256 ws1 = v2__15;
  Lib_IntVector_Intrinsics_vec256 ws2 = v1__15;
  Lib_IntVector_Intrinsics_vec256 ws3 = v3__15;
  Lib_IntVector_Intrinsics_vec256 v017 = ws[4U];
  Lib_IntVector_Intrinsics_vec256 v117 = ws[5U];
  Lib_IntVector_Intrinsics_vec256 v217 = ws[6U];
  Lib_IntVector_Intrinsics_vec256 v317 = ws[7U];
  Lib_IntVector_Intrinsics_vec256
  v0_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v1_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v017, v117);
  Lib_IntVector_Intrinsics_vec256
  v2_16 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v3_16 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v217, v317);
  Lib_IntVector_Intrinsics_vec256
  v0__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v1__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_16, v2_16);
  Lib_IntVector_Intrinsics_vec256
  v2__16 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256
  v3__16 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_16, v3_16);
  Lib_IntVector_Intrinsics_vec256 ws4 = v0__16;
  Lib_IntVector_Intrinsics_vec256 ws5 = v2__16;
  Lib_IntVector_Intrinsics_vec256 ws6 = v1__16;
  Lib_IntVector_Intrinsics_vec256 ws7 = v3__16;
  Lib_IntVector_Intrinsics_vec256 v018 = ws[8U];
  Lib_IntVector_Intrinsics_vec256 v118 = ws[9U];
  Lib_IntVector_Intrinsics_vec256 v218 = ws[10U];
  Lib_IntVector_Intrinsics_vec256 v318 = ws[11U];
  Lib_IntVector_Intrinsics_vec256
  v0_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v1_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v018, v118);
  Lib_IntVector_Intrinsics_vec256
  v2_17 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v3_17 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v218, v318);
  Lib_IntVector_Intrinsics_vec256
  v0__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v1__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_17, v2_17);
  Lib_IntVector_Intrinsics_vec256
  v2__17 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256
  v3__17 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_17, v3_17);
  Lib_IntVector_Intrinsics_vec256 ws8 = v0__17;
  Lib_IntVector_Intrinsics_vec256 ws9 = v2__17;
  Lib_IntVector_Intrinsics_vec256 ws10 = v1__17;
  Lib_IntVector_Intrinsics_vec256 ws11 = v3__17;
  Lib_IntVector_Intrinsics_vec256 v019 = ws[12U];
  Lib_IntVector_Intrinsics_vec256 v119 = ws[13U];
  Lib_IntVector_Intrinsics_vec256 v219 = ws[14U];
  Lib_IntVector_Intrinsics_vec256 v319 = ws[15U];
  Lib_IntVector_Intrinsics_vec256
  v0_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v1_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v019, v119);
  Lib_IntVector_Intrinsics_vec256
  v2_18 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v3_18 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v219, v319);
  Lib_IntVector_Intrinsics_vec256
  v0__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v1__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_18, v2_18);
  Lib_IntVector_Intrinsics_vec256
  v2__18 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256
  v3__18 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_18, v3_18);
  Lib_IntVector_Intrinsics_vec256 ws12 = v0__18;
  Lib_IntVector_Intrinsics_vec256 ws13 = v2__18;
  Lib_IntVector_Intrinsics_vec256 ws14 = v1__18;
  Lib_IntVector_Intrinsics_vec256 ws15 = v3__18;
  Lib_IntVector_Intrinsics_vec256 v020 = ws[16U];
  Lib_IntVector_Intrinsics_vec256 v120 = ws[17U];
  Lib_IntVector_Intrinsics_vec256 v220 = ws[18U];
  Lib_IntVector_Intrinsics_vec256 v320 = ws[19U];
  Lib_IntVector_Intrinsics_vec256
  v0_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v1_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v020, v120);
  Lib_IntVector_Intrinsics_vec256
  v2_19 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v3_19 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v220, v320);
  Lib_IntVector_Intrinsics_vec256
  v0__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v1__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_19, v2_19);
  Lib_IntVector_Intrinsics_vec256
  v2__19 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256
  v3__19 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_19, v3_19);
  Lib_IntVector_Intrinsics_vec256 ws16 = v0__19;
  Lib_IntVector_Intrinsics_vec256 ws17 = v2__19;
  Lib_IntVector_Intrinsics_vec256 ws18 = v1__19;
  Lib_IntVector_Intrinsics_vec256 ws19 = v3__19;
  Lib_IntVector_Intrinsics_vec256 v021 = ws[20U];
  Lib_IntVector_Intrinsics_vec256 v121 = ws[21U];
  Lib_IntVector_Intrinsics_vec256 v221 = ws[22U];
  Lib_IntVector_Intrinsics_vec256 v321 = ws[23U];
  Lib_IntVector_Intrinsics_vec256
  v0_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v1_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v021, v121);
  Lib_IntVector_Intrinsics_vec256
  v2_20 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v3_20 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v221, v321);
  Lib_IntVector_Intrinsics_vec256
  v0__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v1__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_20, v2_20);
  Lib_IntVector_Intrinsics_vec256
  v2__20 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256
  v3__20 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_20, v3_20);
  Lib_IntVector_Intrinsics_vec256 ws20 = v0__20;
  Lib_IntVector_Intrinsics_vec256 ws21 = v2__20;
  Lib_IntVector_Intrinsics_vec256 ws22 = v1__20;
  Lib_IntVector_Intrinsics_vec256 ws23 = v3__20;
  Lib_IntVector_Intrinsics_vec256 v022 = ws[24U];
  Lib_IntVector_Intrinsics_vec256 v122 = ws[25U];
  Lib_IntVector_Intrinsics_vec256 v222 = ws[26U];
  Lib_IntVector_Intrinsics_vec256 v322 = ws[27U];
  Lib_IntVector_Intrinsics_vec256
  v0_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v1_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v022, v122);
  Lib_IntVector_Intrinsics_vec256
  v2_21 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v3_21 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v222, v322);
  Lib_IntVector_Intrinsics_vec256
  v0__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v1__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_21, v2_21);
  Lib_IntVector_Intrinsics_vec256
  v2__21 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256
  v3__21 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_21, v3_21);
  Lib_IntVector_Intrinsics_vec256 ws24 = v0__21;
  Lib_IntVector_Intrinsics_vec256 ws25 = v2__21;
  Lib_IntVector_Intrinsics_vec256 ws26 = v1__21;
  Lib_IntVector_Intrinsics_vec256 ws27 = v3__21;
  Lib_IntVector_Intrinsics_vec256 v0 = ws[28U];
  Lib_IntVector_Intrinsics_vec256 v1 = ws[29U];
  Lib_IntVector_Intrinsics_vec256 v2 = ws[30U];
  Lib_IntVector_Intrinsics_vec256 v3 = ws[31U];
  Lib_IntVector_Intrinsics_vec256
  v0_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v1_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v0, v1);
  Lib_IntVector_Intrinsics_vec256
  v2_22 = Lib_IntVector_Intrinsics_vec256_interleave_low64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v3_22 = Lib_IntVector_Intrinsics_vec256_interleave_high64(v2, v3);
  Lib_IntVector_Intrinsics_vec256
  v0__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v1__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v0_22, v2_22);
  Lib_IntVector_Intrinsics_vec256
  v2__22 = Lib_IntVector_Intrinsics_vec256_interleave_low128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256
  v3__22 = Lib_IntVector_Intrinsics_vec256_interleave_high128(v1_22, v3_22);
  Lib_IntVector_Intrinsics_vec256 ws28 = v0__22;
  Lib_IntVector_Intrinsics_vec256 ws29 = v2__22;
  Lib_IntVector_Intrinsics_vec256 ws30 = v1__22;
  Lib_IntVector_Intrinsics_vec256 ws31 = v3__22;
  ws[0U] = ws0;
  ws[1U] = ws1;
  ws[2U] = ws2;
  ws[3U] = ws3;
  ws[4U] = ws4;
  ws[5U] = ws5;
  ws[6U] = ws6;
  ws[7U] = ws7;
  ws[8U] = ws8;
  ws[9U] = ws9;
  ws[10U] = ws10;
  ws[11U] = ws11;
  ws[12U] = ws12;
  ws[13U] = ws13;
  ws[14U] = ws14;
  ws[15U] = ws15;
  ws[16U] = ws16;
  ws[17U] = ws17;
  ws[18U] = ws18;
  ws[19U] = ws19;
  ws[20U] = ws20;
  ws[21U] = ws21;
  ws[22U] = ws22;
  ws[23U] = ws23;
  ws[24U] = ws24;
  ws[25U] = ws25;
  ws[26U] = ws26;
  ws[27U] = ws27;
  ws[28U] = ws28;
  ws[29U] = ws29;
  ws[30U] = ws30;
  ws[31U] = ws31;
  for (uint32_t i = 0U; i < 32U; i++)
  {
    Lib_IntVector_Intrinsics_vec256_store64_le(hbuf + i * 32U, ws[i]);
  }
  for (uint32_t i = 0U; i < remOut / 32U; i++)
  {
    uint8_t *b3 = rb.snd.snd.snd;
    uint8_t *b2 = rb.snd.snd.fst;
    uint8_t *b1 = rb.snd.fst;
    uint8_t *b0 = rb.fst;
    memcpy(b0 + 64U - remOut + i * 32U, hbuf + i * 128U, 32U * sizeof (uint8_t));
    memcpy(b1 + 64U - remOut + i * 32U, hbuf + i * 128U + 32U, 32U * sizeof (uint8_t));
    memcpy(b2 + 64U - remOut + i * 32U, hbuf + i * 128U + 64U, 32U * sizeof (uint8_t));
    memcpy(b3 + 64U - remOut + i * 32U, hbuf + i * 128U + 96U, 32U * sizeof (uint8_t));
  }
  uint32_t rem0 = remOut % 32U;
  uint32_t j = remOut / 32U;
  uint8_t *b3 = rb.snd.snd.snd;
  uint8_t *b2 = rb.snd.snd.fst;
  uint8_t *b1 = rb.snd.fst;
  uint8_t *b0 = rb.fst;
  memcpy(b0 + 64U - remOut + j * 32U, hbuf + j * 128U, rem0 * sizeof (uint8_t));
  memcpy(b1 + 64U - remOut + j * 32U, hbuf + j * 128U + 32U, rem0 * sizeof (uint8_t));
  memcpy(b2 + 64U - remOut + j * 32U, hbuf + j * 128U + 64U, rem0 * sizeof (uint8_t));
  memcpy(b3 + 64U - remOut + j * 32U, hbuf + j * 128U + 96U, rem0 * sizeof (uint8_t));
}

