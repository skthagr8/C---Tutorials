#include <iostream>
#include <pqxx/pqxx>  // Include libpqxx header


class DatabaseConnector {
    public:
    // Connection String
    std::string conn_str;
    
    // Constructor
    DatabaseConnector(std::string conn_str) : conn_str(conn_str) {}
    
    // Get Connection String
    conn_str getConnStr() {
        return conn_str;
    }

    // Connect to Database
    void connect(){
        try{
            // Connect to PostgreSQL server (not specifying a database yet)
            pqxx::connection C(connection_string);  // Connect to the server, not a specific database

            if (C.is_open()) {
                std::cout << "Connected to PostgreSQL server successfully!" << std::endl;
            } else {
                std::cerr << "Failed to connect to PostgreSQL server!" << std::endl;
            }

        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }


}

int main() {
    try {
      std::string connection_string = "dbname=postgres user=postgres password=postgres hostaddr=";
      DatabaseConnector connector = new DatabaseConnector(connection_string);
      

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
