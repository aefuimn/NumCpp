/// @file
/// @author David Pilger <dpilger26@gmail.com>
/// [GitHub Repository](https://github.com/dpilger26/NumCpp)
/// @version 1.2
///
/// @section License
/// Copyright 2019 David Pilger
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this
/// software and associated documentation files(the "Software"), to deal in the Software
/// without restriction, including without limitation the rights to use, copy, modify,
/// merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
/// permit persons to whom the Software is furnished to do so, subject to the following
/// conditions :
///
/// The above copyright notice and this permission notice shall be included in all copies
/// or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
/// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
/// PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
/// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
/// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
/// @section Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"
#include "NumCpp/Core/StlAlgorithms.hpp"

#include <cmath>

namespace nc
{
    //============================================================================
    // Method Description:
    ///						Calculate exp(x) - 1 for the input value.
    ///
    ///                     NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.expm1.html
    ///
    /// @param
    ///				inValue
    /// @return
    ///				value
    ///
    template<typename dtype>
    double expm1(dtype inValue) noexcept
    {
        return std::exp(static_cast<double>(inValue)) - 1.0;
    }

    //============================================================================
    // Method Description:
    ///						Calculate exp(x) - 1 for all elements in the array.
    ///
    ///                     NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.expm1.html
    ///
    /// @param
    ///				inArray
    /// @return
    ///				NdArray
    ///
    template<typename dtype>
    NdArray<double> expm1(const NdArray<dtype>& inArray) noexcept
    {
        NdArray<double> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(), inArray.cend(), returnArray.begin(),
            [](dtype inValue) noexcept -> double
            {
                return expm1(inValue);
            });

        return returnArray;
    }
}
