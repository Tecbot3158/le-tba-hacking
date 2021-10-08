#!/usr/bin/zsh

curl -H "$TBA_AUTH_HEADER" "${TBA_URL}/event/${TBA_EVENTS_MTY_2019}/teams/simple" | jq length
