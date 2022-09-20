pushd c:\kafka\bin\windows
kafka-console-consumer.bat --bootstrap-server localhost:9092 --topic url_data_topic --from-beginning
popd