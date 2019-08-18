// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// Rtsne_cpp
  Rcpp::List Rtsne_cpp(NumericMatrix X, int no_dims_in, double perplexity_in, double theta_in, bool verbose, int max_iter, bool distance_precomputed, NumericMatrix Y_in, bool init, int stop_lying_iter_in, int mom_switch_iter_in, double momentum_in, double final_momentum_in, double eta_in, double exaggeration_factor_in, unsigned int num_threads_in, LogicalVector fix_in);
  RcppExport SEXP Rtsne_Rtsne_cpp(SEXP XSEXP, SEXP no_dims_inSEXP, SEXP perplexity_inSEXP, SEXP theta_inSEXP, SEXP verboseSEXP, SEXP max_iterSEXP, SEXP distance_precomputedSEXP, SEXP Y_inSEXP, SEXP initSEXP, SEXP stop_lying_iter_inSEXP, SEXP mom_switch_iter_inSEXP, SEXP momentum_inSEXP, SEXP final_momentum_inSEXP, SEXP eta_inSEXP, SEXP exaggeration_factor_inSEXP, SEXP num_threads_inSEXP, SEXP fix_inSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type X(XSEXP);
    Rcpp::traits::input_parameter< int >::type no_dims_in(no_dims_inSEXP);
    Rcpp::traits::input_parameter< double >::type perplexity_in(perplexity_inSEXP);
    Rcpp::traits::input_parameter< double >::type theta_in(theta_inSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< int >::type max_iter(max_iterSEXP);
    Rcpp::traits::input_parameter< bool >::type distance_precomputed(distance_precomputedSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type Y_in(Y_inSEXP);
    Rcpp::traits::input_parameter< bool >::type init(initSEXP);
    Rcpp::traits::input_parameter< int >::type stop_lying_iter_in(stop_lying_iter_inSEXP);
    Rcpp::traits::input_parameter< int >::type mom_switch_iter_in(mom_switch_iter_inSEXP);
    Rcpp::traits::input_parameter< double >::type momentum_in(momentum_inSEXP);
    Rcpp::traits::input_parameter< double >::type final_momentum_in(final_momentum_inSEXP);
    Rcpp::traits::input_parameter< double >::type eta_in(eta_inSEXP);
    Rcpp::traits::input_parameter< double >::type exaggeration_factor_in(exaggeration_factor_inSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type num_threads_in(num_threads_inSEXP);
    rcpp_result_gen = Rcpp::wrap(Rtsne_cpp(X, no_dims_in, perplexity_in, theta_in, verbose, max_iter, distance_precomputed, Y_in, init, stop_lying_iter_in, mom_switch_iter_in, momentum_in, final_momentum_in, eta_in, exaggeration_factor_in, num_threads_in, fix_in));
    return rcpp_result_gen;
END_RCPP
}
