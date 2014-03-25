//   GAMBIT: Global and Modular BSM Inference Tool
//   *********************************************
///  \file
///
///  Exception objects required for standalone
///  compilation.
///
///  *********************************************
///
///  Authors (add name and date if you modify):
///   
///  \author Pat Scott 
///          (patscott@physics.mcgill.ca)
///  \date 2014 Mar
///
///  *********************************************

#include "standalone_error_handlers.hpp"
#include "log_tags.hpp"

namespace Gambit
{
  using namespace LogTags;

  /// Utility errors
  error& utils_error()
  { 
    static error local("A problem has been raised by one of the utility codes.","utils_error", utils); 
    return local;
  }

  /// Utility warnings
  warning& utils_warning()
  { 
    static warning local("A problem has been raised by one of the utility codes.","utils_warning", utils); 
    return local;
  }

  /// Logging errors
  error& logging_error()
  { 
    static error local("A problem has occurred in the logging utilities.","logging_error", logging); 
    return local;
  }

  /// Logging warnings
  warning& logging_warning()
  { 
    static warning local("A problem has occurred in the logging utilities.","logging_warning", logging); 
    return local;
  }

  /// Model errors
  error& model_error()
  {
    static error local("A problem has been encountered in the model subsystem.","model_error", models);
    return local;
  }

  /// Model warnings
  warning& model_warning()
  {
    static warning local("A problem has been encountered in the model subsystem.","model_warning", models);
    return local;
  }

  namespace Printers
  {

    /// Printer errors
    error& printer_error()
    { 
      static error local("A problem has occurred in the printer utilities.","printer_error", printers); 
      return local;
    }

    /// Printer warnings
    warning& printer_warning()
    { 
      static warning local("A problem has occurred in the printer utilities.","printer_warning", printers); 
      return local;
    }

  }
    
}

