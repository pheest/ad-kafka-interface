REM caput -S DMSC:cam1:URL1 http://190.33.204.88:8888/SnapshotJPEG?Resolution=320x240&Quality=Clarity
REM caput -S DMSC:cam1:URL1 http://202.245.13.81/cgi-bin/camera
caput -S DMSC:cam1:URL1 http://202.245.13.81/cgi-bin/mjpeg
REM caput -S DMSC:cam1:URL1 http://190.33.204.88:8888/nphMotionJpeg?Resolution=320x240&Quality=Standard
REM caput -S DMSC:cam1:URL1 http://192.168.100.10/cgi-bin/mjpeg
REM caput -S DMSC:cam1:URL1 http://192.168.100.10/cgi-bin/camera
caput DMSC:cam1:URLSelect.ZRST Panasonic BL-VP101
caput DMSC:cam1:Acquire Acquire
caput DMSC:KFK:Acquire Acquire
