//   GAMBIT: Global and Modular BSM Inference Tool
//   *********************************************
///  \file
///
///  Library of ModelGraph methods.
///  
///  Duties:
///  * Create and track a graph of the model hierarchy,
///    for both visualisation and for relationship 
///    checks
///
///  *********************************************
///
///  Authors
///  =======
///
///  (add name and date if you modify)
///
///  \author Ben Farmer
///          (benjamin.farmer@monash.edu.au)
///  \date 2013 July 17
///
///  \author Pat Scott
///          (patscott@physics.mcgill.ca)
///  \date 2013 Aug, Sep
///  \date 2014 Mar
///
///  *********************************************

#include "modelgraph.hpp"
#include "models.hpp"
#include "stream_printers.hpp"
#include "util_types.hpp"

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>
#include <boost/graph/graphviz.hpp>

namespace Gambit
{

  /// ModelHierarchy method definitions
  /// Creates a graph of the model hierarchy for visualisation purposes.
  /// @{
    
    /// Constructor
    ModelHierarchy::ModelHierarchy(const Models::ModelFunctorClaw& claw, const primodel_vec& pmv, str file, bool talky)
     : boundClaw(&claw), filename(file), verbose(talky)
    {
      makeGraph(pmv);
    }

    /// Figure out relationships between primary model functors    
    void ModelHierarchy::makeGraph(const primodel_vec& primaryModelFunctors)
    {
      boost::graph_traits<DRes::MasterGraphType>::vertex_iterator vi, vi_end;
      std::map<str, DRes::VertexID> vertexIDmap;
      str model;
      
      if (verbose) std::cout<<std::endl<<"Determining model hierarchy graph..."<<std::endl;

      // Add all primary model functors to the model hierarchy graph
      addFunctorsToGraph(primaryModelFunctors);

      // Loop over all vertices (models) in modelGraph and create a map from
      // model names to vertex IDs.
      for (boost::tie(vi, vi_end) = boost::vertices(modelGraph); 
              vi != vi_end; ++vi) 
      {
        model = (*modelGraph[*vi]).origin();
        vertexIDmap[model] = *vi;
        if (verbose) std::cout<<"    Vertex added: "<<model<<std::endl;
      }
      
      // Loop over all vertices (models) in vertexIDmap, look up the 'parent' 
      // of each one in the parents database boundClaw->myParentsDB, and add
      // an edge from parent to child in the model graph.
      typedef std::map<str, DRes::VertexID>::iterator vertexIDmap_it;
      for (vertexIDmap_it vimap = vertexIDmap.begin(); 
              vimap != vertexIDmap.end(); vimap++) 
      {
        model = vimap->first;
        str parent = boundClaw->get_parent(model);  
        if (verbose) std::cout<<model<<"; parent: "<<parent<<std::endl;;       
        // If there is a parent, add an edge between parent and child
        if (parent != "none")
        {
          boost::add_edge(vertexIDmap[parent], vertexIDmap[model], modelGraph);
          if (verbose) std::cout<<"    Edge added: "<<model<<" ---> "<<parent<<std::endl;
        }
      }
      if (verbose) std::cout<<std::endl;
      
      // Generate graphviz plot
      std::ofstream outf(filename);
      write_graphviz(outf, modelGraph, labelWriter(&modelGraph)); 
      
    }

    /// Add model functors to the modelGraph
    void ModelHierarchy::addFunctorsToGraph(const primodel_vec& primaryModelFunctors)
    {
      // - model functors go into modelGraph
      for (std::vector<primary_model_functor *>::const_iterator
          it  = primaryModelFunctors.begin();
          it != primaryModelFunctors.end(); ++it)
      {
        //if ( (*it)->status() != 0 ) 
        boost::add_vertex(*it, modelGraph);     
      }
    }

  /// @}    


  /// ModelHierarchy::labelWriter method definitions
  /// @{

    /// Constructor
    ModelHierarchy::labelWriter::labelWriter(const DRes::MasterGraphType * modelGraph) : myGraph(modelGraph) {}

    void ModelHierarchy::labelWriter::operator()(std::ostream& out, const DRes::VertexID& v) const
    {
      if ( (*myGraph)[v]->status() == 2 )
      {
        out << "[fillcolor=\"red\", style=\"rounded,filled\", shape=box,";
        out << "label=< ";
        out << "<font point-size=\"20\" color=\"black\">" << (*myGraph)[v]->origin() << "</font><br/>";
      }
      else
      {
        out << "[fillcolor=\"#F0F0D0\", style=\"rounded,filled\", shape=box,";
        out << "label=< ";
        out << "<font point-size=\"20\" color=\"red\">" << (*myGraph)[v]->origin() << "</font><br/>";
      } 
      /*out <<  "Type: " << (*myGraph)[v]->type() << "<br/>";
      out <<  "Function: " << (*myGraph)[v]->name() << "<br/>";
      out <<  "Module: " << (*myGraph)[v]->origin();*/
      out << ">]";
    }


}
