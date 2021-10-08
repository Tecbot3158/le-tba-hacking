#!/usr/bin/bash

TBA_URL="https://www.thebluealliance.com/api/v3"

TBA_AUTH_KEY=`cat ~/tba-key`
# replace this line with:
# TBA_AUTH_KEY="yourpassword"

TBA_AUTH_HEADER="X-TBA-Auth-Key: $TBA_AUTH_KEY"


TBA_EVENTS_MTY_2019="2019mxmo"
