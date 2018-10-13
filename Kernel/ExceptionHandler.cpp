//
// Created by pedrosoares on 4/28/18.
//

#include <stdexcept>
#include "ExceptionHandler.h"
#include "Exception.h"

/*
void ExceptionHandler::handle(void (*handler)()) {
    try {
        handler();
    } catch (Exception & exception) {
        // TigreFramework Exception Standard
        //responseStream->write(std::string("Error occurred: ") + exception.what());
    } catch(const std::runtime_error& re) {
        // If any extra code throws a std::runtime_error
        //responseStream->write(std::string("Runtime error: ") + re.what());
    } catch(const std::exception& ex)  {
        // If any extra code throws a std::exception
        //responseStream->write(std::string("Error occurred: ") + ex.what());
    } catch(const std::string& ex)  {
        // If someone have a crazy idea of throw a string it is catched here any way
        //responseStream->write("Error occurred: " + ex);
    } catch (...) {
        // If nothing else cant handle this is used to not make the system out of mind
        //responseStream->write("Unknown Error occurred");
    }
}*/
