pushd c:\kafka\bin\windows
REM https://www.baeldung.com/java-kafka-send-large-message
call kafka-topics.bat --bootstrap-server localhost:9092 --create --topic url_data_topic --config max.message.bytes=10485760
popd
