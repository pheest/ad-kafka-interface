pushd c:\kafka\bin\windows
call kafka-topics.bat --describe --bootstrap-server localhost:9092
popd
