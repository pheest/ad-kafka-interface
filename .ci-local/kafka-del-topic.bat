pushd c:\kafka\bin\windows
call kafka-topics.bat --bootstrap-server localhost:9092 --delete --topic url_data_topic
popd
