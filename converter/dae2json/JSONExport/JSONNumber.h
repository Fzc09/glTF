// Copyright (c) 2012, Motorola Mobility, Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of the Motorola Mobility, Inc. nor the names of its
//    contributors may be used to endorse or promote products derived from this
//    software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef __JSON_NUMBER_H__
#define __JSON_NUMBER_H__

namespace JSONExport 
{
    class JSONNumber : public JSONValue {
    private:
        JSONNumber():JSONValue(JSONExport::NUMBER), _type(NOT_A_NUMBER) {}
        
    public:        
        typedef enum 
        {
            NOT_A_NUMBER = 0,
            UNSIGNED_INT32 = 1,
            INT32 = 2,
            DOUBLE = 3,
            BOOL = 4
        } JSONNumberType;
                
        explicit JSONNumber(unsigned int value);
        explicit JSONNumber(int value);
        explicit JSONNumber(double value);
        explicit JSONNumber(bool value);

        virtual ~JSONNumber();
        
        virtual void write(JSONWriter* writer, void* context = 0);
        
        unsigned int getUnsignedInt32();
        int getInt32();
        double getDouble();
        bool getBool();
        
        JSONNumber::JSONNumberType getType();

    private:
        void* _value;
        JSONNumberType _type;
    };

}


#endif