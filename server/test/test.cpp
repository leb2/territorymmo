#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main(int argc, char* argv[]) {
    try {
        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints =
                resolver.resolve("localhost", "1234");

        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        for (;;) {
            boost::array<char, 128> buf{};
            boost::system::error_code error;
            std::string message = "Test message";
            std::cout << "Starting sending message" << std::endl;

            json command = R"(
                {
                    "commands": [
                        {
                            "command": "move",
                            "target_id": "0"
                        }
                    ]
                }
            )"_json;

            size_t len = socket.send(boost::asio::buffer(command.dump() + "\r"));
            std::cout << "Finished sending message, length: " << len <<  std::endl;

            len = socket.send(boost::asio::buffer("hello2b\r"));
            std::cout << "Finished sending message, length: " << len <<  std::endl;

            len = socket.read_some(boost::asio::buffer(buf), error);
            std::cout << "Finished reading message" << std::endl;

            std::cout << "Response is: " << std::endl;
            std::cout.write(buf.data(), len);

            if (error == boost::asio::error::eof) {
                std::cout << "Connection closed cleanly by peer" << std::endl;
                break;
            } else if (error) {
                throw boost::system::system_error(error); // Some other error.
            }
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
