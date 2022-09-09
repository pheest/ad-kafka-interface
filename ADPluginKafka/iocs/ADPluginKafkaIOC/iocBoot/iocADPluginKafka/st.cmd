< envPaths
errlogInit(20000)

dbLoadDatabase("$(TOP)/dbd/ADPluginKafkaApp.dbd")
ADPluginKafkaApp_registerRecordDeviceDriver(pdbbase)

epicsEnvSet("PREFIX", "$(PREFIX=DMSC)")
epicsEnvSet("ADURL_PORT", "URL1")
epicsEnvSet("K_PORT", "$(PREFIX)K")
epicsEnvSet("XSIZE", "$(XSIZE=200)")
epicsEnvSet("YSIZE", "$(YSIZE=200)")
epicsEnvSet("QSIZE", "20")
epicsEnvSet("EPICS_DB_INCLUDE_PATH", "$(ADCORE)/db")

URLDriverConfig("$(ADURL_PORT)", 0, 0)
dbLoadRecords("$(ADURL)/db/URLDriver.template","P=$(PREFIX),R=cam1:,PORT=$(ADURL_PORT),ADDR=0,TIMEOUT=1")

KafkaPluginConfigure("$(K_PORT)", 3, 1, "$(ADURL_PORT)", 0, -1, "10.4.0.216:9092", "url_data_topic")
dbLoadRecords("$(ADPLUGINKAFKA)/db/ADPluginKafka.template", "P=$(PREFIX),R=:KFK:,PORT=$(K_PORT),ADDR=0,TIMEOUT=1,NDARRAY_PORT=$(ADURL_PORT)")

iocInit()

dbpf $(PREFIX):KFK:EnableCallbacks Enable
dbpf $(PREFIX):SIM:AcquirePeriod 2
dbpf $(PREFIX):SIM:Acquire 1

#Always end with a new line
