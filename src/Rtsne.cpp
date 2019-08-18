#include <Rcpp.h>
#include "tsne.h"
using namespace Rcpp;

// Function that runs the Barnes-Hut implementation of t-SNE
// [[Rcpp::export]]
Rcpp::List Rtsne_cpp(NumericMatrix X, int no_dims_in, double perplexity_in, 
                     double theta_in, bool verbose, int max_iter, 
                     bool distance_precomputed, NumericMatrix Y_in, bool init, 
                     int stop_lying_iter_in, int mom_switch_iter_in,
                     double momentum_in, double final_momentum_in,
		     double eta_in, double exaggeration_factor_in, unsigned int num_threads_in,
		     LogicalVector fix_in) {

  long origN, N, D, no_dims = no_dims_in;

	double  *data;
  double perplexity = perplexity_in;
  double theta = theta_in;
  int stop_lying_iter = stop_lying_iter_in;
  int mom_switch_iter = mom_switch_iter_in;
  double momentum = momentum_in;
  double final_momentum = final_momentum_in;
  double eta = eta_in;
  double exaggeration_factor = exaggeration_factor_in; 
  
  origN = X.nrow();
  D = X.ncol();
    
	data = (double*) calloc(D * origN, sizeof(double));
    if(data == NULL) { Rcpp::stop("Memory allocation failed!\n"); }
    for (unsigned long i = 0; i < origN; i++){
        for (unsigned long j = 0; j < D; j++){
            data[i*D+j] = X(i,j);
        }
    }
    
  N = origN;
  if (verbose) Rprintf("Read the %i x %i data matrix successfully!\n", N, D);


	double* Y = (double*) malloc(N * no_dims * sizeof(double));
	double* costs = (double*) calloc(N, sizeof(double));
	double* itercosts = (double*) calloc((int)(ceil(max_iter/50.0)), sizeof(double));
  if(Y == NULL || costs == NULL) { Rcpp::stop("Memory allocation failed!\n"); }

  bool* fix = (bool*) malloc(N * sizeof(bool));
  if(fix == NULL) {Rcpp::stop("Memoy allocation failes!!\n");}
  for(int i = 0; i < N; i++) fix[i] = fix_in[i];

  // Initialize solution (randomly)
  if (init) {
    for (int i = 0; i < N; i++){
      for (int j = 0; j < no_dims; j++){
        Y[i*no_dims+j] = Y_in(i,j); // Row major storage
      }
    }
    if (verbose) Rprintf("Using user supplied starting positions\n");
  }

    
    // Run tsne
    if (no_dims==1) {
      TSNE<1>* tsne = new TSNE<1>();
      tsne->run(data, N, D, Y, no_dims, perplexity, theta, verbose, max_iter, costs,
		distance_precomputed, itercosts, init, stop_lying_iter, mom_switch_iter, momentum,
		final_momentum, eta, exaggeration_factor, num_threads_in, fix);
		  delete(tsne);
    } else if (no_dims==2)
      {
       TSNE<2>* tsne = new TSNE<2>();
       tsne->run(data, N, D, Y, no_dims, perplexity, theta, verbose, max_iter,
		 costs,distance_precomputed, itercosts, init, stop_lying_iter, mom_switch_iter,
		 momentum, final_momentum, eta, exaggeration_factor, num_threads_in, fix);
       delete(tsne);
      } else if (no_dims==3)
      {
       TSNE<3>* tsne = new TSNE<3>();
       tsne->run(data, N, D, Y, no_dims, perplexity, theta, verbose, max_iter, costs,
		 distance_precomputed, itercosts, init, stop_lying_iter, mom_switch_iter, momentum,
		 final_momentum, eta, exaggeration_factor, num_threads_in, fix);
       delete(tsne);
      } else {
	      Rcpp::stop("Only 1, 2 or 3 dimensional output is suppported.\n");
    }
    
  	// Save the results
    Rcpp::NumericMatrix Yr(N, no_dims);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < no_dims; j++){
            Yr(i,j) = Y[i*no_dims+j];
        }
    }
    
    Rcpp::NumericVector costsr(N);
    for (int i = 0; i < N; i++){
      costsr(i) = costs[i];
    }
    Rcpp::NumericVector itercostsr((int)(ceil(max_iter/50.0)));
    for (int i = 0; i < (int)(ceil(max_iter/50.0)); i++) {
      itercostsr(i) = itercosts[i];
    }
    
    free(data); data = NULL;
  	free(Y); Y = NULL;
		free(costs); costs = NULL;
    
    
    Rcpp::List output = Rcpp::List::create(Rcpp::_["theta"]=theta, 
                                           Rcpp::_["perplexity"]=perplexity, 
                                           Rcpp::_["N"]=N,
                                           Rcpp::_["origD"]=D,
                                           Rcpp::_["Y"]=Yr, 
                                           Rcpp::_["costs"]=costsr, 
                                           Rcpp::_["itercosts"]=itercostsr,
                                           Rcpp::_["stop_lying_iter"]=stop_lying_iter, 
                                           Rcpp::_["mom_switch_iter"]=mom_switch_iter, 
                                           Rcpp::_["momentum"]=momentum, 
                                           Rcpp::_["final_momentum"]=final_momentum, 
                                           Rcpp::_["eta"]=eta, 
                                           Rcpp::_["exaggeration_factor"]=exaggeration_factor);
    return output; 
}
