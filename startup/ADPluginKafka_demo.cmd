epicsEnvSet("PREFIX", "$(PREFIX=YSX26594)")
epicsEnvSet("ADURL_PORT", "URL1")
epicsEnvSet("K_PORT", "$(PREFIX)K")
epicsEnvSet("XSIZE", "$(XSIZE=200)")
epicsEnvSet("YSIZE", "$(YSIZE=200)")
epicsEnvSet("QSIZE", "20")

URLDriverConfig("$(ADURL_PORT)", 0, 0)
dbLoadRecords("$(ADURL)/db/URLDriver.template","P=$(PREFIX),R=cam1:,PORT=$(PORT),ADDR=0,TIMEOUT=1")

KafkaPluginConfigure("$(K_PORT)", 3, 1, "$(ADURL_PORT)", 0, -1, "cs04r-sc-vserv-197:9092", "sim_data_topic")
dbLoadRecords("ADPluginKafka.template", "P=$(PREFIX),R=:KFK:,PORT=$(K_PORT),ADDR=0,TIMEOUT=1,NDARRAY_PORT=$(ADURL_PORT)")

iocInit

dbpf $(PREFIX):KFK:EnableCallbacks Enable
dbpf $(PREFIX):CAM:AcquirePeriod 2
dbpf $(PREFIX):CAM:Acquire 1

#Remember; file MUST end with a new line
