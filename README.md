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


## projects:
- generating an interactive console to write on...
  - made in the glorious C programming language, using...
    - [json-c](https://github.com/json-c/json-c)


# todo:
- read https://ericknavarro.io/2020/10/01/27-Mi-primer-proyecto-utilizando-Yacc-y-Lex/
- read https://duckduckgo.com/?q=TCL+%2F+QT&ia=web
