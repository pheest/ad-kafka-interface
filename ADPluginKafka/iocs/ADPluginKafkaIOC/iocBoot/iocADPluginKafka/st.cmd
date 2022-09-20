< envPaths
errlogInit(20000)

dbLoadDatabase("$(TOP)/dbd/ADPluginKafkaApp.dbd")
ADPluginKafkaApp_registerRecordDeviceDriver(pdbbase)

epicsEnvSet("PREFIX", "$(PREFIX=DMSC)")
epicsEnvSet("ADURL_PORT", "URL1")
epicsEnvSet("K_PORT", "$(PREFIX)K")
# The maximim image width; used for row profiles in the NDPluginStats plugin
epicsEnvSet("XSIZE",  "640")
# The maximim image height; used for column profiles in the NDPluginStats plugin
epicsEnvSet("YSIZE",  "480")
epicsEnvSet("QSIZE", "20")
epicsEnvSet("EPICS_DB_INCLUDE_PATH", "$(ADCORE)/db")

URLDriverConfig("$(ADURL_PORT)", 0, 0)
dbLoadRecords("$(ADURL)/db/URLDriver.template","P=$(PREFIX),R=:cam1:,PORT=$(ADURL_PORT),ADDR=0,TIMEOUT=1")

# Create a standard arrays plugin.
NDStdArraysConfigure("Image1", 3, 0, "$(ADURL_PORT)", 0)
# This waveform only allows transporting 8-bit images
dbLoadRecords("$(ADCORE)/db/NDStdArrays.template", "P=$(PREFIX),R=:image1:,PORT=Image1,ADDR=0,TIMEOUT=1,NDARRAY_PORT=$(ADURL_PORT),TYPE=Int8,FTVL=UCHAR,NELEMENTS=10485760")

# KafkaPluginConfigure(const char *portName, int queueSize, int blockingCallbacks, const char *NDArrayPort, int NDArrayAddr, size_t maxMemory, const char *brokerAddress, const char *topic, const char *sourceName
KafkaPluginConfigure("$(K_PORT)", 3, 1, "$(ADURL_PORT)", 0, -1, "localhost:9092", "url_data_topic", "$(ADURL_PORT)")
dbLoadRecords("$(ADPLUGINKAFKA)/db/ADPluginKafka.template", "P=$(PREFIX),R=:KFK:,PORT=$(K_PORT),ADDR=0,TIMEOUT=1,NDARRAY_PORT=$(ADURL_PORT),FTVL=UCHAR,NELEMENTS=10485760")

# Load all other plugins using commonPlugins.cmd
# < $(ADCORE)/iocBoot/commonPlugins.cmd

iocInit()

dbpf $(PREFIX):KFK:EnableCallbacks Enable
dbpf $(PREFIX):KFK:ArrayCallbacks Enable
dbpf $(PREFIX):cam1:ArrayCallbacks Enable
dbpf $(PREFIX):image1:EnableCallbacks Enable

# NB, the frame rate is hardware-controlled. It makes no sense to set the period to anything other than 0.
dbpf $(PREFIX):cam1:AcquirePeriod 0
