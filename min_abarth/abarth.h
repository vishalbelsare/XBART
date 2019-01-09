//#ifndef SWIG
#include <iostream>
#include <vector>
//#endif
#include "fit_std_main_loop.h"

// #include <cstddef>
// #include <armadillo>
// #include "../src/python_train_forest_std_mtrywithinnode.h"
//double vector
typedef std::vector<double> vec_d; 

//vector of vectors, will be split rules    
typedef std::vector<vec_d> xinfo;      



struct AbarthParams{
			size_t M;
			size_t L;size_t N_sweeps; size_t Nmin; size_t Ncutpoints;
			size_t burnin; size_t mtry;size_t max_depth_num;
			double alpha;double beta;double tau;double kap;double s;
			bool draw_sigma;bool verbose; bool m_update_sigma;
			bool draw_mu;bool parallel;
};

class Abarth{
	private:
		AbarthParams params;
		vec_d y_std;
		size_t n_train; size_t n_test; size_t d;
		xinfo yhats_xinfo; xinfo yhats_test_xinfo; xinfo sigma_draw_xinfo;
		// helper functions
		vec_d np_to_vec_d(int n,double *a);
		vec_d np_to_row_major_vec(int n, int d,double *a);
		vec_d xinfo_to_row_major_vec(xinfo x_std);
		xinfo np_to_xinfo(int n, int d,double *a);
		void xinfo_to_np(xinfo x_std,double *arr);

	
		// void params_to_struct;
	public:
		// Constructors 
		Abarth (AbarthParams params);
		Abarth (size_t M ,size_t L ,size_t N_sweeps ,
				size_t Nmin , size_t Ncutpoints , //CHANGE 
				double alpha , double beta , double tau , //CHANGE!
				size_t burnin, size_t mtry ,
				size_t max_depth_num , bool draw_sigma , double kap , 
				double s , bool verbose , bool m_update_sigma, 
				bool draw_mu , bool parallel);

		// Destructor
		~Abarth();

		// Public Functions 
		int get_M (void);
		int get_N_sweeps(void){return((int)params.N_sweeps);};
		int get_burnin(void){return((int)params.burnin);};
		double fit(int n, double *a);
		double fit_x(int n, int d, double *a);
		//void sort_x(int n, int d, double *a);
		void sort_x(int n,int d,double *a,int size, double *arr);

		void predict(int n,double *a,int size, double *arr);
		void __predict_2d(int n,int d,double *a,int size, double *arr);

		void fit_predict(int n,int d,double *a, // Train X 
			int n_y,double *a_y, // Train Y
			int n_test,int d_test,double *a_test, // Test X
			int size, double *arr); // Result 
		void fit_predict_all(int n,int d,double *a, // Train X 
			int n_y,double *a_y, // Train Y
			int n_test,int d_test,double *a_test, // Test X
			int size, double *arr,size_t p_cat); // Result 
		void get_yhats(int size, double *arr);
		void get_yhats_test(int size, double *arr);
		void get_sigma_draw(int size, double *arr);
};
