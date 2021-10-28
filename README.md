# Le *The Blue Alliance* Hacking

just learning how to use the API.

Here will be scripts to scrape it.


# TBA API Explained
Most of the TBA data will be returned in JSON

## Relevant JSON schemas

### Event
```json
{
key*	string
TBA event key with the format yyyy[EVENT_CODE], where yyyy is the year, and EVENT_CODE is the event code of the event.

name*	string
Official name of event on record either provided by FIRST or organizers of offseason event.

event_code*	string
Event short code, as provided by FIRST.

event_type*	integer
Event Type, as defined here: https://github.com/the-blue-alliance/the-blue-alliance/blob/master/consts/event_type.py#L2

district	District_List{...}
city	string
City, town, village, etc. the event is located in.

state_prov	string
State or Province the event is located in.

country	string
Country the event is located in.

start_date*	string($date)
Event start date in yyyy-mm-dd format.

end_date*	string($date)
Event end date in yyyy-mm-dd format.

year*	integer
Year the event data is for.

short_name	string
Same as name but doesn't include event specifiers, such as 'Regional' or 'District'. May be null.

event_type_string*	string
Event Type, eg Regional, District, or Offseason.

week	integer
Week of the event relative to the first official season event, zero-indexed. Only valid for Regionals, Districts, and District Championships. Null otherwise. (Eg. A season with a week 0 'preseason' event does not count, and week 1 events will show 0 here. Seasons with a week 0.5 regional event will show week 0 for those event(s) and week 1 for week 1 events and so on.)

address	string
Address of the event's venue, if available.

postal_code	string
Postal code from the event address.

gmaps_place_id	string
Google Maps Place ID for the event address.

gmaps_url	string($url)
Link to address location on Google Maps.

lat	number($double)
Latitude for the event address.

lng	number($double)
Longitude for the event address.

location_name	string
Name of the location at the address for the event, eg. Blue Alliance High School.

timezone	string
Timezone name.

website	string
The event's website, if any.

first_event_id	string
The FIRST internal Event ID, used to link to the event on the FRC webpage.

first_event_code	string
Public facing event code used by FIRST (on frc-events.firstinspires.org, for example)

webcasts	[...]
division_keys	[...]
parent_event_key	string
The TBA Event key that represents the event's parent. Used to link back to the event from a division event. It is also the inverse relation of divison_keys.

playoff_type	integer
Playoff Type, as defined here: https://github.com/the-blue-alliance/the-blue-alliance/blob/master/consts/playoff_type.py#L4, or null.

playoff_type_string	string
String representation of the playoff_type, or null.

}
```


## projects:
- generating an interactive console to write on...
  - made in the glorious C programming language, using...
    - [json-c](https://github.com/json-c/json-c)


# todo:
- read https://ericknavarro.io/2020/10/01/27-Mi-primer-proyecto-utilizando-Yacc-y-Lex/
- read https://duckduckgo.com/?q=TCL+%2F+QT&ia=web
