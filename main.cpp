#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;
int main(int ac, const char* av[]) {
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help,h", "help")
            ("rows,r", po::value<int>()->default_value(512), "rows")
            ("cols,c", po::value<int>()->default_value(512), "cols")
            ("lineal,l", po::value<bool>()->default_value(false), "lineal")
            ("row,x", po::value<bool>()->default_value(false), "cols")
            ;

    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (vm.count("rows")) {
        std::cout << "Rows were set to "
             << vm["rows"].as<int>() << ".\n";
    } else {
        std::cout << "Rows were not set.\n";
    }
}