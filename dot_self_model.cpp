// Code generated by Stan version 2.3

#include <stan/model/model_header.hpp>
#include <stan/common/command.hpp>

namespace dot_self_model_namespace {

using std::vector;
using std::string;
using std::stringstream;
using stan::model::prob_grad;
using stan::math::get_base1;
using stan::math::initialize;
using stan::math::stan_print;
using stan::math::lgamma;
using stan::io::dump;
using std::istream;
using namespace stan::math;
using namespace stan::prob;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;

class dot_self_model : public prob_grad {
private:
    int d_int;
    vector_d d_vector;
    row_vector_d d_row_vector;
    double transformed_data_real;
    vector_d transformed_data_vector;
    row_vector_d transformed_data_row_vector;
public:
    dot_self_model(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        static const char* function__ = "dot_self_model_namespace::dot_self_model(%1%)";
        (void) function__; // dummy call to supress warning
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        context__.validate_dims("data initialization", "d_int", "int", context__.to_vec());
        d_int = int(0);
        vals_i__ = context__.vals_i("d_int");
        pos__ = 0;
        d_int = vals_i__[pos__++];
        stan::math::validate_non_negative_index("d_vector", "d_int", d_int);
        d_vector = vector_d(d_int);
        context__.validate_dims("data initialization", "d_vector", "vector_d", context__.to_vec(d_int));
        vals_r__ = context__.vals_r("d_vector");
        pos__ = 0;
        size_t d_vector_i_vec_lim__ = d_int;
        for (size_t i_vec__ = 0; i_vec__ < d_vector_i_vec_lim__; ++i_vec__) {
            d_vector[i_vec__] = vals_r__[pos__++];
        }
        context__.validate_dims("data initialization", "d_row_vector", "row_vector_d", context__.to_vec(d_int));
        stan::math::validate_non_negative_index("d_row_vector", "d_int", d_int);
        d_row_vector = row_vector_d(d_int);
        vals_r__ = context__.vals_r("d_row_vector");
        pos__ = 0;
        size_t d_row_vector_i_vec_lim__ = d_int;
        for (size_t i_vec__ = 0; i_vec__ < d_row_vector_i_vec_lim__; ++i_vec__) {
            d_row_vector[i_vec__] = vals_r__[pos__++];
        }

        // validate data
        transformed_data_real = double(0);
        stan::math::validate_non_negative_index("transformed_data_vector", "d_int", d_int);
        transformed_data_vector = vector_d(d_int);
        stan::math::validate_non_negative_index("transformed_data_row_vector", "d_int", d_int);
        transformed_data_row_vector = row_vector_d(d_int);

        stan::math::assign(transformed_data_real, dot_self(d_vector));
        stan::math::assign(transformed_data_real, dot_self(d_row_vector));

        // validate transformed data

        // set parameter ranges
        num_params_r__ = 0U;
        param_ranges_i__.clear();
        num_params_r__ += d_int;
        num_params_r__ += d_int;
        ++num_params_r__;
    }

    ~dot_self_model() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;


        if (!(context__.contains_r("p_vector")))
            throw std::runtime_error("variable p_vector missing");
        vals_r__ = context__.vals_r("p_vector");
        pos__ = 0U;
        context__.validate_dims("initialization", "p_vector", "vector_d", context__.to_vec(d_int));
        vector_d p_vector(d_int);
        for (int j1__ = 0U; j1__ < d_int; ++j1__)
            p_vector(j1__) = vals_r__[pos__++];
        try { writer__.vector_unconstrain(p_vector); } catch (const std::exception& e) {  throw std::runtime_error(std::string("Error transforming variable p_vector: ") + e.what()); }

        if (!(context__.contains_r("p_row_vector")))
            throw std::runtime_error("variable p_row_vector missing");
        vals_r__ = context__.vals_r("p_row_vector");
        pos__ = 0U;
        context__.validate_dims("initialization", "p_row_vector", "row_vector_d", context__.to_vec(d_int));
        row_vector_d p_row_vector(d_int);
        for (int j1__ = 0U; j1__ < d_int; ++j1__)
            p_row_vector(j1__) = vals_r__[pos__++];
        try { writer__.row_vector_unconstrain(p_row_vector); } catch (const std::exception& e) {  throw std::runtime_error(std::string("Error transforming variable p_row_vector: ") + e.what()); }

        if (!(context__.contains_r("y_p")))
            throw std::runtime_error("variable y_p missing");
        vals_r__ = context__.vals_r("y_p");
        pos__ = 0U;
        context__.validate_dims("initialization", "y_p", "double", context__.to_vec());
        double y_p(0);
        y_p = vals_r__[pos__++];
        try { writer__.scalar_unconstrain(y_p); } catch (const std::exception& e) {  throw std::runtime_error(std::string("Error transforming variable y_p: ") + e.what()); }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        T__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        // model parameters
        stan::io::reader<T__> in__(params_r__,params_i__);

        Eigen::Matrix<T__,Eigen::Dynamic,1>  p_vector;
        (void) p_vector;   // dummy to suppress unused var warning
        if (jacobian__)
            p_vector = in__.vector_constrain(d_int,lp__);
        else
            p_vector = in__.vector_constrain(d_int);

        Eigen::Matrix<T__,1,Eigen::Dynamic>  p_row_vector;
        (void) p_row_vector;   // dummy to suppress unused var warning
        if (jacobian__)
            p_row_vector = in__.row_vector_constrain(d_int,lp__);
        else
            p_row_vector = in__.row_vector_constrain(d_int);

        T__ y_p;
        (void) y_p;   // dummy to suppress unused var warning
        if (jacobian__)
            y_p = in__.scalar_constrain(lp__);
        else
            y_p = in__.scalar_constrain();


        // transformed parameters
        T__ transformed_param_real;
        (void) transformed_param_real;   // dummy to suppress unused var warning
        Eigen::Matrix<T__,Eigen::Dynamic,1>  transformed_param_vector(d_int);
        (void) transformed_param_vector;   // dummy to suppress unused var warning
        stan::math::fill(transformed_param_vector,DUMMY_VAR__);
        Eigen::Matrix<T__,1,Eigen::Dynamic>  transformed_param_row_vector(d_int);
        (void) transformed_param_row_vector;   // dummy to suppress unused var warning
        stan::math::fill(transformed_param_row_vector,DUMMY_VAR__);

        // initialized transformed params to avoid seg fault on val access
        stan::math::fill(transformed_param_real,DUMMY_VAR__);
        stan::math::fill(transformed_param_vector,DUMMY_VAR__);
        stan::math::fill(transformed_param_row_vector,DUMMY_VAR__);

        stan::math::assign(transformed_param_real, dot_self(d_vector));
        stan::math::assign(transformed_param_real, dot_self(d_row_vector));
        stan::math::assign(transformed_param_real, dot_self(transformed_param_vector));
        stan::math::assign(transformed_param_real, dot_self(transformed_param_row_vector));

        // validate transformed parameters
        if (stan::math::is_uninitialized(transformed_param_real)) {
            std::stringstream msg__;
            msg__ << "Undefined transformed parameter: transformed_param_real";
            throw std::runtime_error(msg__.str());
        }
        for (int i0__ = 0; i0__ < d_int; ++i0__) {
            if (stan::math::is_uninitialized(transformed_param_vector(i0__))) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: transformed_param_vector" << '[' << i0__ << ']';
                throw std::runtime_error(msg__.str());
            }
        }
        for (int i0__ = 0; i0__ < d_int; ++i0__) {
            if (stan::math::is_uninitialized(transformed_param_row_vector(i0__))) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: transformed_param_row_vector" << '[' << i0__ << ']';
                throw std::runtime_error(msg__.str());
            }
        }

        const char* function__ = "validate transformed params %1%";
        (void) function__; // dummy to suppress unused var warning
        // model body
        lp_accum__.add(normal_log<propto__>(y_p, 0, 1));

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("p_vector");
        names__.push_back("p_row_vector");
        names__.push_back("y_p");
        names__.push_back("transformed_param_real");
        names__.push_back("transformed_param_vector");
        names__.push_back("transformed_param_row_vector");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(d_int);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(d_int);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(d_int);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(d_int);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        vars__.resize(0);
        stan::io::reader<double> in__(params_r__,params_i__);
        static const char* function__ = "dot_self_model_namespace::write_array(%1%)";
        (void) function__; // dummy call to supress warning
        // read-transform, write parameters
        vector_d p_vector = in__.vector_constrain(d_int);
        row_vector_d p_row_vector = in__.row_vector_constrain(d_int);
        double y_p = in__.scalar_constrain();
        for (int k_0__ = 0; k_0__ < d_int; ++k_0__) {
            vars__.push_back(p_vector[k_0__]);
        }
        for (int k_0__ = 0; k_0__ < d_int; ++k_0__) {
            vars__.push_back(p_row_vector[k_0__]);
        }
        vars__.push_back(y_p);

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__; // dummy call to supress warning
        stan::math::accumulator<double> lp_accum__;

        double transformed_param_real(0.0);
        (void) transformed_param_real;   // dummy to suppress unused var warning
        vector_d transformed_param_vector(d_int);
        (void) transformed_param_vector;   // dummy to suppress unused var warning
        row_vector_d transformed_param_row_vector(d_int);
        (void) transformed_param_row_vector;   // dummy to suppress unused var warning

        stan::math::assign(transformed_param_real, dot_self(d_vector));
        stan::math::assign(transformed_param_real, dot_self(d_row_vector));
        stan::math::assign(transformed_param_real, dot_self(transformed_param_vector));
        stan::math::assign(transformed_param_real, dot_self(transformed_param_row_vector));

        // validate transformed parameters

        // write transformed parameters
        vars__.push_back(transformed_param_real);
        for (int k_0__ = 0; k_0__ < d_int; ++k_0__) {
            vars__.push_back(transformed_param_vector[k_0__]);
        }
        for (int k_0__ = 0; k_0__ < d_int; ++k_0__) {
            vars__.push_back(transformed_param_row_vector[k_0__]);
        }

        if (!include_gqs__) return;
        // declare and define generated quantities


        // validate generated quantities

        // write generated quantities
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }


    void write_csv_header(std::ostream& o__) const {
        stan::io::csv_writer writer__(o__);
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            writer__.comma();
            o__ << "p_vector" << '.' << k_0__;
        }
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            writer__.comma();
            o__ << "p_row_vector" << '.' << k_0__;
        }
        writer__.comma();
        o__ << "y_p";
        writer__.comma();
        o__ << "transformed_param_real";
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            writer__.comma();
            o__ << "transformed_param_vector" << '.' << k_0__;
        }
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            writer__.comma();
            o__ << "transformed_param_row_vector" << '.' << k_0__;
        }
        writer__.newline();
    }

    template <typename RNG>
    void write_csv(RNG& base_rng__,
                   std::vector<double>& params_r__,
                   std::vector<int>& params_i__,
                   std::ostream& o__,
                   std::ostream* pstream__ = 0) const {
        stan::io::reader<double> in__(params_r__,params_i__);
        stan::io::csv_writer writer__(o__);
        static const char* function__ = "dot_self_model_namespace::write_csv(%1%)";
        (void) function__; // dummy call to supress warning
        // read-transform, write parameters
        vector_d p_vector = in__.vector_constrain(d_int);
        writer__.write(p_vector);
        row_vector_d p_row_vector = in__.row_vector_constrain(d_int);
        writer__.write(p_row_vector);
        double y_p = in__.scalar_constrain();
        writer__.write(y_p);

        // declare, define and validate transformed parameters
        double lp__ = 0.0;
        (void) lp__; // dummy call to supress warning
        stan::math::accumulator<double> lp_accum__;

        double transformed_param_real(0.0);
        (void) transformed_param_real;   // dummy to suppress unused var warning
        vector_d transformed_param_vector(d_int);
        (void) transformed_param_vector;   // dummy to suppress unused var warning
        row_vector_d transformed_param_row_vector(d_int);
        (void) transformed_param_row_vector;   // dummy to suppress unused var warning

        stan::math::assign(transformed_param_real, dot_self(d_vector));
        stan::math::assign(transformed_param_real, dot_self(d_row_vector));
        stan::math::assign(transformed_param_real, dot_self(transformed_param_vector));
        stan::math::assign(transformed_param_real, dot_self(transformed_param_row_vector));


        // write transformed parameters
        writer__.write(transformed_param_real);
        writer__.write(transformed_param_vector);
        writer__.write(transformed_param_row_vector);

        // declare and define generated quantities


        // validate generated quantities

        // write generated quantities
        writer__.newline();
    }

    template <typename RNG>
    void write_csv(RNG& base_rng,
                   Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                   std::ostream& o,
                   std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<int> params_i_vec;  // dummy
      write_csv(base_rng, params_r_vec, params_i_vec, o, pstream);
    }

    static std::string model_name() {
        return "dot_self_model";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "p_vector" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "p_row_vector" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "y_p";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "transformed_param_real";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "transformed_param_vector" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "transformed_param_row_vector" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "p_vector" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "p_row_vector" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "y_p";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "transformed_param_real";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "transformed_param_vector" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= d_int; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "transformed_param_row_vector" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__) return;
    }

}; // model

} // namespace

int main(int argc, const char* argv[]) {
    try {
        return stan::common::command<dot_self_model_namespace::dot_self_model>(argc,argv);
    } catch (const std::exception& e) {
        std::cerr << std::endl << "Exception: " << e.what() << std::endl;
        std::cerr << "Diagnostic information: " << std::endl << boost::diagnostic_information(e) << std::endl;
        return -1;
    }
}

typedef dot_self_model_namespace::dot_self_model stan_model;

