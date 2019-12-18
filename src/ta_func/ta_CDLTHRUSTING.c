/* TA-LIB Copyright (c) 1999-2007, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  AC       Angelo Ciceri
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  121204 AC   Creation
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */
/* Generated */ #if defined(_MANAGED)
    /* Generated */ #include "TA-Lib-Core.h"
    /* Generated */ #define TA_INTERNAL_ERROR(Id)(RetCode::InternalError)
    /* Generated */ namespace TicTacTec {
  namespace TA {
  namespace Library {
  /* Generated */ #elif defined(_JAVA)
      /* Generated */ #include "ta_defs.h"
      /* Generated */ #include "ta_java_defs.h"
      /* Generated */ #define TA_INTERNAL_ERROR(Id)(RetCode.InternalError)
      /* Generated */ #else
      /* Generated */ #include <string.h>
      /* Generated */ #include <math.h>
      /* Generated */ #include "ta_func.h"
      /* Generated */ #endif
      /* Generated */
      /* Generated */ #ifndef TA_UTILITY_H
      /* Generated */ #include "ta_utility.h"
      /* Generated */ #endif
      /* Generated */
      /* Generated */ #ifndef TA_MEMORY_H
      /* Generated */ #include "ta_memory.h"
      /* Generated */ #endif
      /* Generated */
      /* Generated */ #define TA_PREFIX(x) TA_##x
      /* Generated */ #define INPUT_TYPE double
      /* Generated */
      /* Generated */ #if defined(_MANAGED)
      /* Generated */ int Core::CdlThrustingLookback(void)
      /* Generated */
      /* Generated */ #elif defined(_JAVA)
      /* Generated */ public int cdlThrustingLookback()
      /* Generated */
      /* Generated */ #else
      /* Generated */ int TA_CDLTHRUSTING_Lookback(void)
      /* Generated */
      /* Generated */ #endif
  /**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
  {
    /* insert local variable here */

    /**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
    /* Generated */ /* No parameters to validate. */
                    /**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/

    /* insert lookback code here. */
    return max(TA_CANDLEAVGPERIOD(Equal), TA_CANDLEAVGPERIOD(BodyLong)) + 1;
  }

  /**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
  /*
   * TA_CDLTHRUSTING - Thrusting Pattern
   *
   * Input  = Open, High, Low, Close
   * Output = int
   *
   */
  /* Generated */
  /* Generated */ #if defined(_MANAGED) && defined(USE_SUBARRAY)
      /* Generated */ enum class Core::RetCode Core::CdlThrusting(
          int startIdx,
          /* Generated */ int endIdx,
          /* Generated */ SubArray ^ inOpen,
          /* Generated */ SubArray ^ inHigh,
          /* Generated */ SubArray ^ inLow,
          /* Generated */ SubArray ^ inClose,
          /* Generated */[Out] int % outBegIdx,
          /* Generated */[Out] int % outNBElement,
          /* Generated */ cli::array <int> ^ outInteger)
      /* Generated */ #elif defined(_MANAGED)
      /* Generated */ enum class Core::RetCode Core::CdlThrusting(
          int startIdx,
          /* Generated */ int endIdx,
          /* Generated */ cli::array <double> ^ inOpen,
          /* Generated */ cli::array <double> ^ inHigh,
          /* Generated */ cli::array <double> ^ inLow,
          /* Generated */ cli::array <double> ^ inClose,
          /* Generated */[Out] int % outBegIdx,
          /* Generated */[Out] int % outNBElement,
          /* Generated */ cli::array <int> ^ outInteger)
      /* Generated */ #elif defined(_JAVA)
      /* Generated */ public RetCode
      cdlThrusting(int startIdx,
                   /* Generated */ int endIdx,
                   /* Generated */ double inOpen[],
                   /* Generated */ double inHigh[],
                   /* Generated */ double inLow[],
                   /* Generated */ double inClose[],
                   /* Generated */ MInteger outBegIdx,
                   /* Generated */ MInteger outNBElement,
                   /* Generated */ int outInteger[])
      /* Generated */ #else
      /* Generated */ TA_RetCode
      TA_CDLTHRUSTING(int startIdx,
                      /* Generated */ int endIdx,
                      /* Generated */ const double inOpen[],
                      /* Generated */ const double inHigh[],
                      /* Generated */ const double inLow[],
                      /* Generated */ const double inClose[],
                      /* Generated */ int *outBegIdx,
                      /* Generated */ int *outNBElement,
                      /* Generated */ int outInteger[])
      /* Generated */ #endif
  /**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
  {
    /* Insert local variables here. */
    double EqualPeriodTotal, BodyLongPeriodTotal;
    int i, outIdx, EqualTrailingIdx, BodyLongTrailingIdx, lookbackTotal;

    /**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
    /* Generated */
    /* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
        /* Generated */
        /* Generated */ /* Validate the requested output range. */
        /* Generated */ if (startIdx < 0)
        /* Generated */ return ENUM_VALUE(RetCode, TA_OUT_OF_RANGE_START_INDEX,
                                          OutOfRangeStartIndex);
    /* Generated */ if ((endIdx < 0) || (endIdx < startIdx))
      /* Generated */ return ENUM_VALUE(RetCode, TA_OUT_OF_RANGE_END_INDEX,
                                        OutOfRangeEndIndex);
    /* Generated */
    /* Generated */ #if !defined(_JAVA)
        /* Generated */ /* Verify required price component. */
        /* Generated */ if (!inOpen || !inHigh || !inLow || !inClose)
        /* Generated */ return ENUM_VALUE(RetCode, TA_BAD_PARAM, BadParam);
    /* Generated */
    /* Generated */ #endif /* !defined(_JAVA)*/
        /* Generated */ #if !defined(_JAVA)
        /* Generated */ if (!outInteger)
        /* Generated */ return ENUM_VALUE(RetCode, TA_BAD_PARAM, BadParam);
    /* Generated */
    /* Generated */ #endif     /* !defined(_JAVA) */
        /* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
                               /* Generated */
        /**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

        /* Identify the minimum number of price bar needed
         * to calculate at least one output.
         */

        lookbackTotal = LOOKBACK_CALL(CDLTHRUSTING)();

    /* Move up the start index if there is not
     * enough initial data.
     */
    if (startIdx < lookbackTotal)
      startIdx = lookbackTotal;

    /* Make sure there is still something to evaluate. */
    if (startIdx > endIdx) {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNBElement);
      return ENUM_VALUE(RetCode, TA_SUCCESS, Success);
    }

    /* Do the calculation using tight loops. */
    /* Add-up the initial period, except for the last value. */
    EqualPeriodTotal = 0;
    EqualTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(Equal);
    BodyLongPeriodTotal = 0;
    BodyLongTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(BodyLong);

    i = EqualTrailingIdx;
    while (i < startIdx) {
      EqualPeriodTotal += TA_CANDLERANGE(Equal, i - 1);
      i++;
    }
    i = BodyLongTrailingIdx;
    while (i < startIdx) {
      BodyLongPeriodTotal += TA_CANDLERANGE(BodyLong, i - 1);
      i++;
    }
    i = startIdx;

    /* Proceed with the calculation for the requested range.
     * Must have:
     * - first candle: long black candle
     * - second candle: white candle with open below previous day low and close
     * into previous day body under the midpoint; to differentiate it from
     * in-neck the close should not be equal to the black candle's close The
     * meaning of "equal" is specified with TA_SetCandleSettings outInteger is
     * negative (-1 to -100): thrusting pattern is always bearish the user
     * should consider that the thrusting pattern is significant when it appears
     * in a downtrend and it could be even bullish "when coming in an uptrend or
     * occurring twice within several days" (Steve Nison says), while this
     * function does not consider the trend
     */
    outIdx = 0;
    do {
      if (TA_CANDLECOLOR(i - 1) == -1 && // 1st: black
          TA_REALBODY(i - 1) >
              TA_CANDLEAVERAGE(BodyLong, BodyLongPeriodTotal, i - 1) && //  long
          TA_CANDLECOLOR(i) == 1 &&   // 2nd: white
          inOpen[i] < inLow[i - 1] && //  open below prior low
          inClose[i] > inClose[i - 1] +
                           TA_CANDLEAVERAGE(Equal, EqualPeriodTotal,
                                            i - 1) && //  close into prior body
          inClose[i] <=
              inClose[i - 1] + TA_REALBODY(i - 1) * 0.5 //   under the midpoint
      )
        outInteger[outIdx++] = -100;
      else
        outInteger[outIdx++] = 0;
      /* add the current range and subtract the first range: this is done after
       * the pattern recognition when avgPeriod is not 0, that means "compare
       * with the previous candles" (it excludes the current candle)
       */
      EqualPeriodTotal += TA_CANDLERANGE(Equal, i - 1) -
                          TA_CANDLERANGE(Equal, EqualTrailingIdx - 1);
      BodyLongPeriodTotal += TA_CANDLERANGE(BodyLong, i - 1) -
                             TA_CANDLERANGE(BodyLong, BodyLongTrailingIdx - 1);
      i++;
      EqualTrailingIdx++;
      BodyLongTrailingIdx++;
    } while (i <= endIdx);

    /* All done. Indicate the output limits and return. */
    VALUE_HANDLE_DEREF(outNBElement) = outIdx;
    VALUE_HANDLE_DEREF(outBegIdx) = startIdx;

    return ENUM_VALUE(RetCode, TA_SUCCESS, Success);
  }

  /**** START GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/
  /* Generated */
  /* Generated */ #define USE_SINGLE_PRECISION_INPUT
      /* Generated */ #if !defined(_MANAGED) &&
      !defined(_JAVA)
      /* Generated */ #undef TA_PREFIX
      /* Generated */ #define TA_PREFIX(x) TA_S_##x
      /* Generated */ #endif
      /* Generated */ #undef INPUT_TYPE
      /* Generated */ #define INPUT_TYPE float
      /* Generated */ #if defined(_MANAGED)
      /* Generated */ enum class Core::RetCode
      Core::CdlThrusting(int startIdx,
                         /* Generated */ int endIdx,
                         /* Generated */ cli::array <float> ^ inOpen,
                         /* Generated */ cli::array <float> ^ inHigh,
                         /* Generated */ cli::array <float> ^ inLow,
                         /* Generated */ cli::array <float> ^ inClose,
                         /* Generated */[Out] int % outBegIdx,
                         /* Generated */[Out] int % outNBElement,
                         /* Generated */ cli::array <int> ^ outInteger)
      /* Generated */ #elif defined(_JAVA)
      /* Generated */ public RetCode
      cdlThrusting(int startIdx,
                   /* Generated */ int endIdx,
                   /* Generated */ float inOpen[],
                   /* Generated */ float inHigh[],
                   /* Generated */ float inLow[],
                   /* Generated */ float inClose[],
                   /* Generated */ MInteger outBegIdx,
                   /* Generated */ MInteger outNBElement,
                   /* Generated */ int outInteger[])
      /* Generated */ #else
      /* Generated */ TA_RetCode
      TA_S_CDLTHRUSTING(int startIdx,
                        /* Generated */ int endIdx,
                        /* Generated */ const float inOpen[],
                        /* Generated */ const float inHigh[],
                        /* Generated */ const float inLow[],
                        /* Generated */ const float inClose[],
                        /* Generated */ int *outBegIdx,
                        /* Generated */ int *outNBElement,
                        /* Generated */ int outInteger[])
      /* Generated */ #endif
  /* Generated */ {
    /* Generated */ double EqualPeriodTotal, BodyLongPeriodTotal;
    /* Generated */ int i, outIdx, EqualTrailingIdx, BodyLongTrailingIdx,
        lookbackTotal;
    /* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
        /* Generated */ if (startIdx < 0)
        /* Generated */ return ENUM_VALUE(RetCode, TA_OUT_OF_RANGE_START_INDEX,
                                          OutOfRangeStartIndex);
    /* Generated */ if ((endIdx < 0) || (endIdx < startIdx))
      /* Generated */ return ENUM_VALUE(RetCode, TA_OUT_OF_RANGE_END_INDEX,
                                        OutOfRangeEndIndex);
    /* Generated */ #if !defined(_JAVA)
        /* Generated */ if (!inOpen || !inHigh || !inLow || !inClose)
        /* Generated */ return ENUM_VALUE(RetCode, TA_BAD_PARAM, BadParam);
    /* Generated */ #endif
        /* Generated */ #if !defined(_JAVA)
        /* Generated */ if (!outInteger)
        /* Generated */ return ENUM_VALUE(RetCode, TA_BAD_PARAM, BadParam);
    /* Generated */ #endif
        /* Generated */ #endif
        /* Generated */ lookbackTotal = LOOKBACK_CALL(CDLTHRUSTING)();
    /* Generated */ if (startIdx < lookbackTotal)
      /* Generated */ startIdx = lookbackTotal;
    /* Generated */ if (startIdx > endIdx)
    /* Generated */ {
      /* Generated */ VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      /* Generated */ VALUE_HANDLE_DEREF_TO_ZERO(outNBElement);
      /* Generated */ return ENUM_VALUE(RetCode, TA_SUCCESS, Success);
/* Generated */    }
/* Generated */ EqualPeriodTotal = 0;
/* Generated */ EqualTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(Equal);
/* Generated */ BodyLongPeriodTotal = 0;
/* Generated */ BodyLongTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(BodyLong);
/* Generated */ i = EqualTrailingIdx;
/* Generated */ while (i < startIdx) {
  /* Generated */ EqualPeriodTotal += TA_CANDLERANGE(Equal, i - 1);
  /* Generated */ i++;
/* Generated */    }
/* Generated */ i = BodyLongTrailingIdx;
/* Generated */ while (i < startIdx) {
  /* Generated */ BodyLongPeriodTotal += TA_CANDLERANGE(BodyLong, i - 1);
  /* Generated */ i++;
/* Generated */    }
/* Generated */ i = startIdx;
/* Generated */ outIdx = 0;
/* Generated */ do
/* Generated */ {
  /* Generated */ if (TA_CANDLECOLOR(i - 1) == -1 && // 1st: black
                      /* Generated */ TA_REALBODY(i - 1) >
                          TA_CANDLEAVERAGE(BodyLong, BodyLongPeriodTotal,
                                           i - 1) &&            //  long
                      /* Generated */ TA_CANDLECOLOR(i) == 1 && // 2nd: white
                      /* Generated */ inOpen[i] <
                          inLow[i - 1] && //  open below prior low
                      /* Generated */ inClose[i] >
                          inClose[i - 1] +
                              TA_CANDLEAVERAGE(
                                  Equal, EqualPeriodTotal,
                                  i - 1) && //  close into prior body
                      /* Generated */ inClose[i] <=
                          inClose[i - 1] +
                              TA_REALBODY(i - 1) * 0.5 //   under the midpoint
                      /* Generated */)
    /* Generated */ outInteger[outIdx++] = -100;
  /* Generated */ else
    /* Generated */ outInteger[outIdx++] = 0;
  /* Generated */ EqualPeriodTotal +=
      TA_CANDLERANGE(Equal, i - 1) -
      TA_CANDLERANGE(Equal, EqualTrailingIdx - 1);
  /* Generated */ BodyLongPeriodTotal +=
      TA_CANDLERANGE(BodyLong, i - 1)
      /* Generated */
      - TA_CANDLERANGE(BodyLong, BodyLongTrailingIdx - 1);
  /* Generated */ i++;
  /* Generated */ EqualTrailingIdx++;
  /* Generated */ BodyLongTrailingIdx++;
/* Generated */    } while( i <= endIdx );
/* Generated */ VALUE_HANDLE_DEREF(outNBElement) = outIdx;
/* Generated */ VALUE_HANDLE_DEREF(outBegIdx) = startIdx;
/* Generated */ return ENUM_VALUE(RetCode, TA_SUCCESS, Success);
/* Generated */ }
/* Generated */
/* Generated */ #if defined(_MANAGED)
/* Generated */ // namespace Library
}
} // namespace TA
} // Close namespace TicTacTec.TA.Lib
/* Generated */ #endif
    /**** END GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/
