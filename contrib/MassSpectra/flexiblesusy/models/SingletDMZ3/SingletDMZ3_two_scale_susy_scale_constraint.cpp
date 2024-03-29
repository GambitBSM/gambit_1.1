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

// File generated at Sat 27 Aug 2016 12:43:56

#include "SingletDMZ3_two_scale_susy_scale_constraint.hpp"
#include "SingletDMZ3_two_scale_model.hpp"
#include "wrappers.hpp"
#include "logger.hpp"
#include "ew_input.hpp"
#include "gsl_utils.hpp"
#include "minimizer.hpp"
#include "root_finder.hpp"
#include "threshold_loop_functions.hpp"

#include <cassert>
#include <cmath>

namespace flexiblesusy {

#define DERIVEDPARAMETER(p) model->p()
#define INPUTPARAMETER(p) model->get_input().p
#define MODELPARAMETER(p) model->get_##p()
#define PHASE(p) model->get_##p()
#define BETAPARAMETER(p) beta_functions.get_##p()
#define BETA(p) beta_##p
#define LowEnergyConstant(p) Electroweak_constants::p
#define MZPole qedqcd.displayPoleMZ()
#define STANDARDDEVIATION(p) Electroweak_constants::Error_##p
#define Pole(p) model->get_physical().p
#define SCALE model->get_scale()
#define THRESHOLD static_cast<int>(model->get_thresholds())
#define MODEL model
#define MODELCLASSNAME SingletDMZ3<Two_scale>

SingletDMZ3_susy_scale_constraint<Two_scale>::SingletDMZ3_susy_scale_constraint()
   : Constraint<Two_scale>()
   , scale(0.)
   , initial_scale_guess(0.)
   , model(0)
   , qedqcd()
{
}

SingletDMZ3_susy_scale_constraint<Two_scale>::SingletDMZ3_susy_scale_constraint(
   SingletDMZ3<Two_scale>* model_, const softsusy::QedQcd& qedqcd_)
   : Constraint<Two_scale>()
   , model(model_)
   , qedqcd(qedqcd_)
{
   initialize();
}

SingletDMZ3_susy_scale_constraint<Two_scale>::~SingletDMZ3_susy_scale_constraint()
{
}

void SingletDMZ3_susy_scale_constraint<Two_scale>::apply()
{
   assert(model && "Error: SingletDMZ3_susy_scale_constraint::apply():"
          " model pointer must not be zero");



   model->calculate_DRbar_masses();
   update_scale();

   // apply user-defined susy scale constraints
   MODEL->solve_ewsb();


}

double SingletDMZ3_susy_scale_constraint<Two_scale>::get_scale() const
{
   return scale;
}

double SingletDMZ3_susy_scale_constraint<Two_scale>::get_initial_scale_guess() const
{
   return initial_scale_guess;
}

const SingletDMZ3_input_parameters& SingletDMZ3_susy_scale_constraint<Two_scale>::get_input_parameters() const
{
   assert(model && "Error: SingletDMZ3_susy_scale_constraint::"
          "get_input_parameters(): model pointer is zero.");

   return model->get_input();
}

SingletDMZ3<Two_scale>* SingletDMZ3_susy_scale_constraint<Two_scale>::get_model() const
{
   return model;
}

void SingletDMZ3_susy_scale_constraint<Two_scale>::set_model(Two_scale_model* model_)
{
   model = cast_model<SingletDMZ3<Two_scale>*>(model_);
}

void SingletDMZ3_susy_scale_constraint<Two_scale>::set_sm_parameters(
   const softsusy::QedQcd& qedqcd_)
{
   qedqcd = qedqcd_;
}

const softsusy::QedQcd& SingletDMZ3_susy_scale_constraint<Two_scale>::get_sm_parameters() const
{
   return qedqcd;
}

void SingletDMZ3_susy_scale_constraint<Two_scale>::clear()
{
   scale = 0.;
   initial_scale_guess = 0.;
   model = NULL;
   qedqcd = softsusy::QedQcd();
}

void SingletDMZ3_susy_scale_constraint<Two_scale>::initialize()
{
   assert(model && "SingletDMZ3_susy_scale_constraint<Two_scale>::"
          "initialize(): model pointer is zero.");

   const auto QEWSB = INPUTPARAMETER(QEWSB);

   initial_scale_guess = QEWSB;

   scale = initial_scale_guess;
}

void SingletDMZ3_susy_scale_constraint<Two_scale>::update_scale()
{
   assert(model && "SingletDMZ3_susy_scale_constraint<Two_scale>::"
          "update_scale(): model pointer is zero.");

   const auto QEWSB = INPUTPARAMETER(QEWSB);

   scale = QEWSB;


}

} // namespace flexiblesusy
