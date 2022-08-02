#include <gtkmm.h>
#include "main_app.h"

int main(int argc, char *argv[])
{
    auto app = MainApplication::create();
    
    return app->run(argc, argv);
}
