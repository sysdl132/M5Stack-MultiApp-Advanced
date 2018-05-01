#include "M5StackSAM.h"

class WebRadioClass
{
public:
  WebRadioClass();
  ~WebRadioClass();

  void Run();

private:
  AudioGenerator *player = NULL;
  AudioFileSourceICYStream *file = NULL;
  AudioFileSourceBuffer *buff = NULL;
  AudioOutputI2S *out = NULL;

  const int preallocateBufferSize = 8192;
  const int preallocateCodecSize = 29192; // AAC+SBR codec max mem needed
  void *preallocateBuffer = NULL;
  void *preallocateCodec = NULL;

  std::vector<String> Name;
  std::vector<String> Link;
  String StationList, name, link, old_Station = "";
  int SignalStrength;
  unsigned int Station = 0;
  unsigned int fillLvl, rawFillLvl = 1;
  unsigned long now;
  unsigned long lastcheck;
  bool play = true;
  bool upd = true;

  void getvolume();
  void setVolume(int *v);
  bool GetStations(fs::FS &fs, const char *path);
  void StopPlaying();
};