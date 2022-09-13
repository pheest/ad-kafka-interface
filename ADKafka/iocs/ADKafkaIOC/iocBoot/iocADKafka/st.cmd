< envPaths
errlogInit(20000)

dbLoadDatabase("$(TOP)/dbd/ADKafkaApp.dbd")
ADKafkaApp_registerRecordDeviceDriver(pdbbase)

epicsEnvSet("PREFIX", "$(PREFIX=DMSC)")
epicsEnvSet("KFKDET_PORT", "$(PREFIX)_AD_KAFKA")
epicsEnvSet("K_PORT", "$(PREFIX)K")
epicsEnvSet("QSIZE", "20")
epicsEnvSet("EPICS_DB_INCLUDE_PATH", "$(ADCORE)/db")


KafkaDriverConfigure("$(KFKDET_PORT)", 10, 0, 0, 0, "localhost:9092", "url_data_topic")
dbLoadRecords("$(ADKAFKA)/db/ADKafka.template", "P=$(PREFIX):, R=KFK_DRVR:, PORT=$(KFKDET_PORT), ADDR=0, TIMEOUT=1")

NDPvaConfigure("PVA", $(QSIZE), 0, "$(KFKDET_PORT)", 0, $(PREFIX):PVA:Image, 0, 0, 0)
dbLoadRecords("NDPva.template",  "P=$(PREFIX):,R=PVA:, PORT=PVA,ADDR=0,TIMEOUT=1,NDARRAY_PORT=$(KFKDET_PORT)")

# Create a standard arrays plugin.
NDStdArraysConfigure("Image1", 3, 0, "$(ADURL_PORT)", 0)
# This waveform only allows transporting 8-bit images
dbLoadRecords("$(ADCORE)/db/NDStdArrays.template", "P=$(PREFIX),R=:image1:,PORT=Image1,ADDR=0,TIMEOUT=1,NDARRAY_PORT=$(ADURL_PORT),TYPE=Int8,FTVL=UCHAR,NELEMENTS=12582912")


startPVAServer()

iocInit()

dbpf $(PREFIX):PVA:EnableCallbacks Enable
dbpf $(PREFIX):kafka1:EnableCallbacks Enable
