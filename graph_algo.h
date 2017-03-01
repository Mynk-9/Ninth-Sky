/**

Copyright 2017 Mayank Mathur

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#ifndef ERROR_SUBMISSION_9THSKY
#include "error_submission.h"
#endif

#ifndef GRAPH_ALGO_9THSKY
#define GRAPH_ALGO_9THSKY

#include <map>
#include <vector>

#include "graph.h"

namespace ninth_sky
{
    /**
    *   @brief      Uses the Bellman-Ford Algorithm to find shortest path
    *               between a source vertex and all others.
    *               Returns the path weight.
    *   @param      graph <VERTEX_TYPE>     :   Graph on which algorithm should
    *                                           be used.
    *   @param      src                     :   Source vertex
    */
    template <typename VERTEX_TYPE>
    std::map <VERTEX_TYPE, int> bellman_ford (ninth_sky::graph <VERTEX_TYPE> & g, const VERTEX_TYPE& src)
    {
        std::map <VERTEX_TYPE, int> distance;
        for (VERTEX_TYPE vt : g.getAllVertexesById())
			distance[vt] = INT_MAX;
		distance[src] = 0;

		std::vector < std::pair <VERTEX_TYPE, int> > tmp;
		bool change = true;
		int count = 0;

		while (change && count++ < g.vertexCount())
		{
			change = false;
			for (std::pair <VERTEX_TYPE, int> u : distance)					/// u -> {VERTEX_TYPE, path_weight}
			{
				if (u.second != INT_MAX)
				{
					for (std::pair <VERTEX_TYPE, int> n : g.getNeighbours(u.first))
					{
						int weight = u.second + n.second;
						if (distance[n.first] > weight && n.first != src)
						{
							change = true;
							distance[n.first] = weight;
						}
					}
				}
			}
		}

		return distance;
    }
}


#endif
