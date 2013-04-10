//
//  StereoFixedTestGen.h
//  Tonic 
//
//  Created by Nick Donaldson on 3/9/13.

//
// See LICENSE.txt for license and usage information.
//


#ifndef __Tonic__StereoFixedTestGen__
#define __Tonic__StereoFixedTestGen__

#include "Generator.h"

namespace Tonic {
  
  namespace Tonic_ {
    
    class StereoFixedTestGen_ : public Generator_{
      
    protected:
      
      void computeSynthesisBlock( const SynthesisContext_ & context);
      
      float lVal_;
      float rVal_;
      
    public:
      StereoFixedTestGen_();
      ~StereoFixedTestGen_();
      
      void setLVal(float l){ lVal_ = l; };
      void setRVal(float r){ rVal_ = r; };
      
    };
    
    inline void StereoFixedTestGen_::computeSynthesisBlock( const SynthesisContext_ & context)
    {
      float* buffStart = &synthesisBlock_[0];
      
        
      #ifdef USE_APPLE_ACCELERATE
        
      vDSP_vfill( &lVal_ , buffStart, 2, synthesisBlock_.frames());
      vDSP_vfill( &rVal_ , buffStart+1, 2, synthesisBlock_.frames());
      
      #else
      
      for (unsigned int i=0; i<synthesisBlock_.frames(); i++){
        *buffStart++ = lVal_;
        *buffStart++ = rVal_;
      }
      
      #endif
      
    }
    
  }
  
  class StereoFixedTestGen : public TemplatedGenerator<Tonic_::StereoFixedTestGen_>{
    
  public:
    
    StereoFixedTestGen(float left, float right)
    {
      gen()->setLVal(left);
      gen()->setRVal(right);
      gen()->setIsStereoOutput(true);
    }

  };
}

#endif /* defined(__Tonic__StereoFixedTestGen__) */


