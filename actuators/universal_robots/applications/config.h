// This file is part of snark, a generic and flexible library for robotics research
// Copyright (c) 2011 The University of Sydney
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. All advertising materials mentioning features or use of this software
//    must display the following acknowledgement:
//    This product includes software developed by the The University of Sydney.
// 4. Neither the name of the The University of Sydney nor the
//    names of its contributors may be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
// GRANTED BY THIS LICENSE.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
// HOLDERS AND CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
// BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
// IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <comma/csv/traits.h>

namespace comma { namespace ur { 

struct config_t 
{
    struct move_options_t 
    { 
        typedef double type; 
        type acceleration; 
        type speed; 
        type radius; 
    };
    move_options_t move_options;
};

} } // namespace comma { namespace ur { 

namespace comma { namespace visiting {    

  template <> struct traits< comma::ur::config_t >
{
    template< typename K, typename V > static void visit( const K&, comma::ur::config_t& t, V& v )
    {
        v.apply( "move-options", t.move_options );
    }
    
    template< typename K, typename V > static void visit( const K&, const comma::ur::config_t& t, V& v )
    {
        v.apply( "move-options", t.move_options );
    }
};
      
template <> struct traits< comma::ur::config_t::move_options_t >
{
    template< typename K, typename V > static void visit( const K&, comma::ur::config_t::move_options_t& t, V& v )
    {
        v.apply( "acceleration", t.acceleration );
        v.apply( "speed", t.speed );
        v.apply( "radius", t.radius );
    }    
    
    template< typename K, typename V > static void visit( const K&, const comma::ur::config_t::move_options_t& t, V& v )
    {
        v.apply( "acceleration", t.acceleration );
        v.apply( "speed", t.speed );
        v.apply( "radius", t.radius );
    }
};

} } // namespace comma { namespace visiting {