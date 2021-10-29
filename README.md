## Le *The Blue Alliance* Hacking

just learning how to use the API.

Here will be scripts to scrape it.

This project attempts to adhere to [Semantic Versioning](https://semver.org/).

# TBA API Explained
Most of the TBA data will be returned in JSON

## Relevant JSON schemas

### Event
```json
{
  "city": "Ciudad de México",
  "country": "Mexico",
  "district": null,
  "end_date": "2019-03-16",
  "event_code": "mxcm",
  "event_type": 0,
  "key": "2019mxcm",
  "name": "Regional de la Ciudad de Mexico",
  "start_date": "2019-03-13",
  "state_prov": "CDMX",
  "year": 2019
}
```
the `key` object-string will be the one used when using the API from 
The Blue Alliance. This will allow you to download all of the relevant
data to that event/match, including score specifics, teams, winner team, 
etc.

# working releases
- `src/cjson/`
  - run `make all` to compile and run code, it will use the cJSON library (just a single header and a C source file,
  already included in the folder). It will use the library to remove any events that do not correspond to the desired country.
  Ideally, there will be a more standarized way of specifying which country and year ranges. Currently, it works on a single 
  json static file and will output the information to the `stdout` stream.
  - Ideally, this will turn into a query language which in turn serves as an API to work with some scouting and data
  analysis stuff. 


## projects:
- generating an interactive console to write on...
  - made in the glorious C programming language, using...
  - honestly, this `json-c` library didn't seem to work that well, 
	I think [`cJSON`](https://github.com/DaveGamble/cJSON) seems to work better. Note: I've only tried these two
	so take my opinion like a grain of salt.
    - [json-c](https://github.com/json-c/json-c)


# todo:
- read https://ericknavarro.io/2020/10/01/27-Mi-primer-proyecto-utilizando-Yacc-y-Lex/
- read https://duckduckgo.com/?q=TCL+%2F+QT&ia=web
