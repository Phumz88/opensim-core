#ifndef _MarkerSet_h_
#define _MarkerSet_h_
// MarkerSet.h
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
* Copyright (c) 2005, Stanford University. All rights reserved. 
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions
* are met: 
*  - Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer. 
*  - Redistributions in binary form must reproduce the above copyright 
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the distribution. 
*  - Neither the name of the Stanford University nor the names of its 
*    contributors may be used to endorse or promote products derived 
*    from this software without specific prior written permission. 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
* POSSIBILITY OF SUCH DAMAGE. 
*/

/*  
 * Author:  
 */

// INCLUDES
#include <OpenSim/Simulation/rdSimulationDLL.h>
#include "Marker.h"
#include <OpenSim/Tools/Set.h>

namespace OpenSim { 

class Pipeline40;
class Storage;
class Model;
class ScaleSet;

//=============================================================================
//=============================================================================
/*
 * A Class representing a markerA set of markers
 *
 * @author Ayman Habib
 * @version 1.0
 */
#ifdef SWIG
	#ifdef RDSIMULATION_API
		#undef RDSIMULATION_API
		#define RDSIMULATION_API
	#endif
#endif

class RDSIMULATION_API MarkerSet : public Set<Marker>
{
private:
	void setNull();
public:
//=============================================================================
// METHODS
//=============================================================================
	//--------------------------------------------------------------------------
	// CONSTRUCTION
	//--------------------------------------------------------------------------
	MarkerSet();
	MarkerSet(const std::string& markersFileName);
	MarkerSet(const MarkerSet& aMarkerSet);
	~MarkerSet(void);
	//--------------------------------------------------------------------------
	// OPERATORS
	//--------------------------------------------------------------------------
#ifndef SWIG
	MarkerSet& operator=(const MarkerSet &aMarkerSet);
#endif
	//--------------------------------------------------------------------------
	// UTILITIES
	//--------------------------------------------------------------------------
	bool usesWeights() const;
	bool bindMarkersToModel(Model *model);
	void getMarkerNames(Array<std::string>& aMarkerNamesArray);
	void scale(ScaleSet& scaleSet);
	void makeRelativeToCom(Model *model);
	const Set<Marker> &getMarkers() const;
};

}; //namespace
#endif
