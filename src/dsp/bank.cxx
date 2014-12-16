/*
 * Author: Harry van Haaren 2014
 *         harryhaaren@gmail.com
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include "bank.hxx"

#include "pad.hxx"
#include <stdio.h>
#include <cstring>

namespace Fabla2
{

Bank::Bank( Fabla2DSP* d, int rate, int ID, const char* name ) :
  dsp( d ),
  ID_( ID )
{
}

void Bank::name( const char* name )
{
  memcpy( name_, name, 20 );
  name_[20] = '\n';
}

void Bank::addPad( Pad* p )
{
#ifdef FABLA2_DEBUG
  printf("%s : %i : Adding pad %i\n", __PRETTY_FUNCTION__, ID_, p->ID() );
#endif // FABLA2_DEBUG
  pads.push_back( p );
}

Bank::~Bank()
{
}

}; // Fabla2