// ====================================================================
// This file is part of FlexibleSUSY.
//
// FlexibleSUSY is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License,
// or (at your option) any later version.
//
// FlexibleSUSY is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with FlexibleSUSY.  If not, see
// <http://www.gnu.org/licenses/>.
// ====================================================================

// File generated at Sat 27 Aug 2016 12:40:10

#ifndef HSSUSY_TWO_SCALE_susy_parameters_H
#define HSSUSY_TWO_SCALE_susy_parameters_H

#include "betafunction.hpp"
#include "HSSUSY_input_parameters.hpp"

#include <iosfwd>
#include <string>
#include <vector>
#include <Eigen/Core>

namespace flexiblesusy {

#ifdef TRACE_STRUCT_TYPE
   #undef TRACE_STRUCT_TYPE
#endif
#define TRACE_STRUCT_TYPE Susy_traces

class HSSUSY_susy_parameters : public Beta_function {
public:
   explicit HSSUSY_susy_parameters(const HSSUSY_input_parameters& input_ = HSSUSY_input_parameters());
   HSSUSY_susy_parameters(double scale_, double loops_, double thresholds_, const HSSUSY_input_parameters& input_, double g1_, double g2_, double g3_, double Lambdax_, const Eigen::Matrix<
   double,3,3>& Yu_, const Eigen::Matrix<double,3,3>& Yd_, const Eigen::Matrix<
   double,3,3>& Ye_
);
   virtual ~HSSUSY_susy_parameters() {}
   virtual Eigen::ArrayXd beta() const;
   virtual Eigen::ArrayXd get() const;
   virtual void print(std::ostream&) const;
   virtual void set(const Eigen::ArrayXd&);
   const HSSUSY_input_parameters& get_input() const;
   HSSUSY_input_parameters& get_input();
   void set_input_parameters(const HSSUSY_input_parameters&);

   HSSUSY_susy_parameters calc_beta() const;
   virtual void clear();

   void set_g1(double g1_) { g1 = g1_; }
   void set_g2(double g2_) { g2 = g2_; }
   void set_g3(double g3_) { g3 = g3_; }
   void set_Lambdax(double Lambdax_) { Lambdax = Lambdax_; }
   void set_Yu(const Eigen::Matrix<double,3,3>& Yu_) { Yu = Yu_; }
   void set_Yu(int i, int k, double value) { Yu(i,k) = value; }
   void set_Yd(const Eigen::Matrix<double,3,3>& Yd_) { Yd = Yd_; }
   void set_Yd(int i, int k, double value) { Yd(i,k) = value; }
   void set_Ye(const Eigen::Matrix<double,3,3>& Ye_) { Ye = Ye_; }
   void set_Ye(int i, int k, double value) { Ye(i,k) = value; }

   double get_g1() const { return g1; }
   double get_g2() const { return g2; }
   double get_g3() const { return g3; }
   double get_Lambdax() const { return Lambdax; }
   const Eigen::Matrix<double,3,3>& get_Yu() const { return Yu; }
   double get_Yu(int i, int k) const { return Yu(i,k); }
   const Eigen::Matrix<double,3,3>& get_Yd() const { return Yd; }
   double get_Yd(int i, int k) const { return Yd(i,k); }
   const Eigen::Matrix<double,3,3>& get_Ye() const { return Ye; }
   double get_Ye(int i, int k) const { return Ye(i,k); }



protected:
   double g1;
   double g2;
   double g3;
   double Lambdax;
   Eigen::Matrix<double,3,3> Yu;
   Eigen::Matrix<double,3,3> Yd;
   Eigen::Matrix<double,3,3> Ye;

   HSSUSY_input_parameters input;

private:
   static const int numberOfParameters = 31;

   struct Susy_traces {
      double traceYdAdjYd;
      double traceYeAdjYe;
      double traceYuAdjYu;
      double traceYdAdjYdYdAdjYd;
      double traceYeAdjYeYeAdjYe;
      double traceYuAdjYuYuAdjYu;
      double traceYdAdjYuYuAdjYd;
      double traceYdAdjYdYdAdjYdYdAdjYd;
      double traceYdAdjYdYdAdjYuYuAdjYd;
      double traceYdAdjYuYuAdjYdYdAdjYd;
      double traceYdAdjYuYuAdjYuYuAdjYd;
      double traceYeAdjYeYeAdjYeYeAdjYe;
      double traceYuAdjYuYuAdjYuYuAdjYu;

   };
   void calc_susy_traces(Susy_traces&) const;

   double calc_beta_g1_one_loop(const TRACE_STRUCT_TYPE&) const;
   double calc_beta_g1_two_loop(const TRACE_STRUCT_TYPE&) const;
   double calc_beta_g1_three_loop(const TRACE_STRUCT_TYPE&) const;
   double calc_beta_g2_one_loop(const TRACE_STRUCT_TYPE&) const;
   double calc_beta_g2_two_loop(const TRACE_STRUCT_TYPE&) const;
   double calc_beta_g2_three_loop(const TRACE_STRUCT_TYPE&) const;
   double calc_beta_g3_one_loop(const TRACE_STRUCT_TYPE&) const;
   double calc_beta_g3_two_loop(const TRACE_STRUCT_TYPE&) const;
   double calc_beta_g3_three_loop(const TRACE_STRUCT_TYPE&) const;
   double calc_beta_Lambdax_one_loop(const TRACE_STRUCT_TYPE&) const;
   double calc_beta_Lambdax_two_loop(const TRACE_STRUCT_TYPE&) const;
   double calc_beta_Lambdax_three_loop(const TRACE_STRUCT_TYPE&) const;
   Eigen::Matrix<double,3,3> calc_beta_Yu_one_loop(const TRACE_STRUCT_TYPE&) const;
   Eigen::Matrix<double,3,3> calc_beta_Yu_two_loop(const TRACE_STRUCT_TYPE&) const;
   Eigen::Matrix<double,3,3> calc_beta_Yu_three_loop(const TRACE_STRUCT_TYPE&) const;
   Eigen::Matrix<double,3,3> calc_beta_Yd_one_loop(const TRACE_STRUCT_TYPE&) const;
   Eigen::Matrix<double,3,3> calc_beta_Yd_two_loop(const TRACE_STRUCT_TYPE&) const;
   Eigen::Matrix<double,3,3> calc_beta_Yd_three_loop(const TRACE_STRUCT_TYPE&) const;
   Eigen::Matrix<double,3,3> calc_beta_Ye_one_loop(const TRACE_STRUCT_TYPE&) const;
   Eigen::Matrix<double,3,3> calc_beta_Ye_two_loop(const TRACE_STRUCT_TYPE&) const;
   Eigen::Matrix<double,3,3> calc_beta_Ye_three_loop(const TRACE_STRUCT_TYPE&) const;

};

std::ostream& operator<<(std::ostream&, const HSSUSY_susy_parameters&);

#undef TRACE_STRUCT_TYPE

} // namespace flexiblesusy

#endif
