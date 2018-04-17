#include <ctime>
#include <RcppArmadillo.h>
#include "tree.h"
#include "treefuns.h"
#include "forest.h"
#include "utility.h"

// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]
Rcpp::List train_forest_std(Rcpp::NumericMatrix y_rcpp, Rcpp::NumericMatrix X_rcpp, Rcpp::NumericMatrix Xtest_rcpp, size_t M, size_t L, size_t N_sweeps, Rcpp::NumericMatrix max_depth_rcpp, size_t Nmin, double alpha, double beta, double tau, bool draw_sigma, double kap = 16, double s = 4, bool verbose = false, bool m_update_sigma = false, bool draw_mu = false){

    // matrices are stacked by column
    size_t p = X_rcpp.ncol();
    size_t N = X_rcpp.nrow();

    // define matrices
    xinfo X = create_xinfo(X_rcpp);
    xinfo Xtest = create_xinfo(Xtest_rcpp);
    xinfo_sizet Xorder = create_xinfo_sizet(Xorder_rcpp);







    // size_t N = X.n_rows;

    // arma::umat Xorder(X.n_rows, X.n_cols);
    // for(size_t i = 0; i < X.n_cols; i++){
    //     Xorder.col(i) = arma::sort_index(X.col(i));
    // }


    // arma::mat yhats = arma::zeros<arma::mat>(X.n_rows, N_sweeps);

    // arma::mat yhats_test = arma::zeros<arma::mat>(Xtest.n_rows, N_sweeps);

    // // save predictions of each tree
    // arma::mat predictions(X.n_rows, M);

    // // save predictions (based on theta_noise) of each tree
    // // arma::mat predictions_theta_noise(X.n_rows, M);

    // arma::mat predictions_test(Xtest.n_rows, M);

    // arma::vec yhat = arma::sum(predictions, 1);

    // arma::vec yhat_test = arma::zeros<arma::vec>(Xtest.n_rows);

    // // current residual
    // arma::vec residual;

    // // current residual (based on theta_noise)
    // // arma::vec residual_theta_noise;

    // arma::mat sigma_draw(M, N_sweeps);

    // double sigma;

    // // double tau;

    // forest trees(M);

    // arma::vec reshat;

    // arma::vec reshat_test;


    // for(size_t mc = 0; mc < L; mc ++ ){

    //     // initialize
    //     predictions.fill(arma::as_scalar(arma::mean(y)) / (double) M);

    //     // predictions_theta_noise.fill(arma::as_scalar(arma::mean(y)) / (double) M);

    //     predictions_test.fill(arma::as_scalar(arma::mean(y)) / (double) M);

    //     yhat = arma::sum(predictions, 1);

    //     yhat_test = arma::sum(predictions_test, 1);

    //     residual = y - yhat;

    //     // residual_theta_noise = y - yhat;

    //     for(size_t sweeps = 0; sweeps < N_sweeps; sweeps ++){

    //         if(verbose == true){
    //         cout << "--------------------------------" << endl;
    //         cout << "number of sweeps " << sweeps << endl;
    //         cout << "--------------------------------" << endl;
    //         }

    //         for(size_t tree_ind = 0; tree_ind < M; tree_ind ++){


    //             // if update sigma based on residual of all m trees
    //             if(m_update_sigma == true){
    //                  sigma = 1.0 / sqrt(arma::as_scalar(arma::randg(1, arma::distr_param( (N + kap) / 2.0, 2.0 / as_scalar(sum(pow(residual, 2)) + s)))));
    //             }

    //             // save sigma
    //             sigma_draw(tree_ind, sweeps) = sigma;

    //             // add prediction of current tree back to residual
    //             // then it's m - 1 trees residual
    //             residual = residual + predictions.col(tree_ind);

    //             // do the samething for residual_theta_noise, residual of m - 1 trees
    //             // residual_theta_noise = residual_theta_noise + predictions_theta_noise.col(tree_ind);

    //             // prediction of m - 1 trees
    //             yhat = yhat - predictions.col(tree_ind);

    //             // prediction of m - 1 trees on testing set
    //             yhat_test = yhat_test - predictions_test.col(tree_ind);

    //             // grow a tree
    //             trees.t[tree_ind].grow_tree_2(residual, arma::as_scalar(mean(residual)), Xorder, X, 0, max_depth(tree_ind, sweeps), Nmin, tau, sigma, alpha, beta, residual, draw_sigma, draw_mu);


    //             if(verbose == true){
    //             cout << "tree " << tree_ind << " size is " << trees.t[tree_ind].treesize() << endl;
    //             }
                
    //             // update prediction of current tree
    //             predictions.col(tree_ind) = fit_new(trees.t[tree_ind], X);

    //             // update prediction (theta_noise) of current tree
    //             // predictions_theta_noise.col(tree_ind) = fit_new_theta_noise(trees.t[tree_ind], X);

    //             // update prediction of current tree, test set
    //             predictions_test.col(tree_ind) = fit_new(trees.t[tree_ind], Xtest);

    //             // fit_new_void(trees.t[tree], Xtest, predictions_test, tree);

    //             // update sigma based on residual of m - 1 trees, residual_theta_noise
    //             if(m_update_sigma == false){

    //                 sigma = 1.0 / sqrt(arma::as_scalar(arma::randg(1, arma::distr_param( (N + kap) / 2.0, 2.0 / as_scalar(sum(pow(residual, 2)) + s)))));

    //             }

    //             // update residual, now it's residual of m trees
    //             residual = residual - predictions.col(tree_ind);

    //             // residual_theta_noise = residual_theta_noise - predictions_theta_noise.col(tree_ind);

    //             yhat = yhat + predictions.col(tree_ind);

    //             yhat_test = yhat_test + predictions_test.col(tree_ind);

    //         }
    //     yhats.col(sweeps) = yhat;
    //     yhats_test.col(sweeps) = yhat_test;
    //     }

    // }

    // return Rcpp::List::create(Rcpp::Named("yhats") = yhats, Rcpp::Named("yhats_test") = yhats_test, Rcpp::Named("sigma") = sigma_draw);
    return Rcpp::List::create(Rcpp::Named("aaa") = 1.0);
}
