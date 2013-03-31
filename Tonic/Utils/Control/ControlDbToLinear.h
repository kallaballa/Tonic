//
//  ControlDbToLinear.h
//  Tonic 
//
//  Created by Nick Donaldson on 3/24/13.
//  Copyright (c) 2013 Morgan Packard. All rights reserved.
//
// See LICENSE.txt for license and usage information.
//


#ifndef __Tonic__ControlDbToLinear__
#define __Tonic__ControlDbToLinear__

#include "ControlConditioner.h"

namespace Tonic {
  
  namespace Tonic_ {

    class ControlDbToLinear_ : public ControlConditioner_{
      
    protected:
      void computeOutput(const SynthesisContext_ & context);
      
    public:
      ControlDbToLinear_();
      ~ControlDbToLinear_();
      
    };
    
  }
  
  class ControlDbToLinear : public TemplatedControlConditioner<ControlDbToLinear, Tonic_::ControlDbToLinear_>{
    
  public:

  };
}

#endif /* defined(__Tonic__ControlDbToLinear__) */


