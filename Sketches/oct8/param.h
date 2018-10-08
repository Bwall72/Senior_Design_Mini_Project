#define MAX_COUNT 100

typedef unsigned char uchar;
typedef unsigned int uint;

HardwareSerial Serial1(1);
COBD obd;

const byte pids[] = {PID_SPEED, PID_RPM};

int current_time = millis();

String speeds[MAX_COUNT];
String rpms[MAX_COUNT];
String times[MAX_COUNT];
uchar buff_loc = 0;

int
take_reading(void)
{
  int response[sizeof(pids)];
  float t = millis() / 1000.;

  if (obd.readPID(pids, sizeof(pids), response) == sizeof(pids)) {
    speeds[buff_loc] = String(response[0]);
    rpms[buff_loc] = String(response[1]);
    times[buff_loc] = String(millis() / 1000.);
    ++buff_loc %= MAX_COUNT;
    return buff_loc;
  }

  return -1;
}

String
create_url(void) 
{
  String url = "https://auto-tracker.azurewebsites.net/index.php/?SPEED=";

  for (int i = 0; i < MAX_COUNT-1; i++) {
    url += speeds[i] + ",";
  }
  url += speeds[MAX_COUNT-1] + "&RPM=";

  for (int i = 0; i < MAX_COUNT-1; i++) {
    url += rpms[i] + ",";
  }
  url += rpms[MAX_COUNT-1] + "&time=";

  for (int i = 0; i < MAX_COUNT-1; i++) {
    url += String(times[i]) + ",";
  }
  url += times[MAX_COUNT-1];

  return url;
}

// Expected from network.h
// char *ssid = "xxx";
// char *pswd = "xxx";

HTTPClient http;
void
WiFi_connect(void)
{
  WiFi.begin(ssid, pswd);

  Serial.print("Connecting to " + String(ssid));
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void
HTTP_post(void)
{
  String url = create_url();
  http.begin(url);
  Serial.println(url);
  http.POST(url);
  http.end();
}

