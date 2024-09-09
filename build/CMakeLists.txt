cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project("ChatApplication")

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# colour for the messages in terminal
if(NOT WIN32)
    string(ASCII 27 Esc)
    set(ColourReset "${Esc}[m")
    set(Yellow "${Esc}[33m")
    set(Magenta "${Esc}[35m")
    set(Cyan "${Esc}[36m")
endif()

# Adds an optionable flag. Can be used for the command line to conditionally build server or client files. 
option(CMAKE_SERVER_BUILD "Only Build and Compile Server" OFF)
option(CMAKE_CLIENT_BUILD "Only Build and Compile Client" OFF) 

# if CMAKE_SERVER_BUILD server is set to ON within the command line 
if(CMAKE_SERVER_BUILD)
    message(STATUS "${Cyan}Building the Server${ColourReset}")
    # adds the server definition flag for the programme to use when compiling. 
    add_definitions(-DSERVERBUILD)
elseif(CMAKE_CLIENT_BUILD)
    message(STATUS "${Magenta}Building the Client${ColourReset}")
    # adds the client definition flag for the programme to use when compiling. 
    add_definitions(-DCLIENTBUILD)
endif()

# creates separate variables which store the needed files for each type of build.  
file(GLOB SHAREDSOURCES
    ../src/Comms/Comms.cpp
    ../src/main.cpp
)

file(GLOB CLIENTSOURCES
    ../src/Client/Client.cpp
    ${SHAREDSOURCES}
)

file(GLOB SERVERSOURCES
    ../src/Server/Server.cpp
    ${SHAREDSOURCES}
)

file(GLOB ALLSOURCES
    ${CLIENTSOURCES}
    ${SERVERSOURCES}
    ${SHAREDSOURCES}
)

# build the correct build dependent on the command line input. 
if(CMAKE_SERVER_BUILD)
    message(STATUS "${Yellow}Creating Server Build${ColourReset}")
    add_executable(server ${SERVERSOURCES})  
elseif(CMAKE_CLIENT_BUILD)
    message(STATUS "${Yellow}Creating Client Build${ColourReset}")
    add_executable(client ${CLIENTSOURCES})
else()
    message(STATUS "${Yellow}Creating Common Build${ColourReset}")
    add_executable(chatApplication ${ALLSOURCES})
endif()