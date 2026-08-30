ROOT := $(CURDIR)
LOCAL_PYTHON := $(ROOT)/tools/environments/python/bin/python
SPLAT := $(ROOT)/tools/environments/python/bin/splat
PYTHON ?= $(if $(wildcard $(LOCAL_PYTHON)),$(LOCAL_PYTHON),python3)
BOOTSTRAP_PYTHON ?= python3

export HOME := $(ROOT)/tmp/home
export TMPDIR := $(ROOT)/tmp
export XDG_CACHE_HOME := $(ROOT)/tmp/cache
export PIP_CACHE_DIR := $(ROOT)/tmp/pip-cache
export PYTHONPYCACHEPREFIX := $(ROOT)/tmp/pycache
export NPM_CONFIG_CACHE := $(ROOT)/tmp/npm-cache
export CARGO_HOME := $(ROOT)/tools/environments/cargo
export RUSTUP_HOME := $(ROOT)/tools/environments/rustup
export GOPATH := $(ROOT)/tools/environments/go
export GOMODCACHE := $(ROOT)/tools/environments/go/pkg/mod

.DEFAULT_GOAL := help

.PHONY: help workspace verify-inputs tools python-tools toolchain check-tools info extract map split build match progress clean

help:
	@printf '%s\n' \
		'Available targets:' \
		'  tools          Install pinned project tools beneath tools/' \
		'  check-tools    Verify pinned local project tools' \
		'  info           Show the verified PS-X executable header' \
		'  extract        Extract the verified header and loaded payload' \
		'  map            Validate the top-level executable region map' \
		'  split          Split the executable into temporary analysis output' \
		'  build          Build the assembly/data PS-X executable baseline' \
		'  match          Build and compare the complete target executable' \
		'  progress       Generate current resident-code progress metrics' \
		'  clean          Remove known generated project output under tmp/' \
		'  verify-inputs  Validate the SLUS-01411 executable and DATA files' \
		'  workspace      Validate that commands are running from the project root'

workspace:
	@$(PYTHON) tools/project/workspace.py

verify-inputs: workspace
	@$(PYTHON) tools/project/verify_inputs.py

tools: python-tools toolchain

python-tools: verify-inputs
	@$(BOOTSTRAP_PYTHON) tools/bootstrap/bootstrap.py

toolchain: verify-inputs
	@$(BOOTSTRAP_PYTHON) tools/bootstrap/binutils.py

check-tools: workspace
	@$(PYTHON) tools/bootstrap/bootstrap.py --check
	@$(PYTHON) tools/bootstrap/binutils.py --check

info: verify-inputs
	@$(PYTHON) tools/project/psx_exe.py info

extract: verify-inputs
	@$(PYTHON) tools/project/psx_exe.py extract

map: verify-inputs
	@$(PYTHON) tools/project/validate_image_map.py

split: map check-tools
	@$(PYTHON) tools/project/clean.py splat
	@$(SPLAT) split config/slus_01411/split.yaml

build: split
	@$(PYTHON) tools/project/clean.py project-build
	@$(PYTHON) tools/project/build_baseline.py

match: build
	@$(PYTHON) tools/project/match.py

progress: split
	@$(PYTHON) tools/project/progress.py

clean: workspace
	@$(PYTHON) tools/project/clean.py extract splat project-build reports
